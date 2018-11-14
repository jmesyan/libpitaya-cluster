#include "pitaya/cluster.h"
#include "pitaya/constants.h"
#include "pitaya/etcdv3_service_discovery.h"
#include "pitaya/nats/rpc_client.h"
#include "pitaya/nats/rpc_server.h"
#include "pitaya/utils.h"
#include "protos/msg.pb.h"
#include <cpprest/json.h>
#include <spdlog/sinks/stdout_color_sinks.h>

using namespace pitaya;
using namespace std;
namespace json = web::json;
using boost::optional;

using google::protobuf::MessageLite;

namespace pitaya {

using etcdv3_service_discovery::Etcdv3ServiceDiscovery;
using service_discovery::ServiceDiscovery;

void
Cluster::Initialize(etcdv3_service_discovery::Config&& sdConfig,
                    nats::NatsConfig&& natsConfig,
                    Server server,
                    RpcHandlerFunc rpcServerHandlerFunc,
                    const char* loggerName)
{
    Initialize(server,
               std::unique_ptr<ServiceDiscovery>(
                   new Etcdv3ServiceDiscovery(std::move(sdConfig), server, loggerName)),
               std::unique_ptr<RpcServer>(
                   new nats::NatsRpcServer(server, natsConfig, rpcServerHandlerFunc, loggerName)),
               std::unique_ptr<RpcClient>(new nats::NatsRpcClient(server, natsConfig, loggerName)));
}

void
Cluster::Initialize(Server server,
                    std::unique_ptr<service_discovery::ServiceDiscovery> sd,
                    std::unique_ptr<RpcServer> rpcServer,
                    std::unique_ptr<RpcClient> rpcClient,
                    const char* loggerName)
{
    _log = ((loggerName && spdlog::get(loggerName)) ? spdlog::get(loggerName)->clone("cluster")
                                                    : spdlog::stdout_color_mt("cluster"));
    _sd = std::move(sd);
    _rpcSv = std::move(rpcServer);
    _rpcClient = std::move(rpcClient);
    _server = server;
}

Cluster::~Cluster()
{
    Terminate();
}

void
Cluster::Terminate()
{
    _sd.reset();
    _rpcSv.reset();
    _rpcClient.reset();

    _log->flush();
    spdlog::drop("cluster");
}

optional<PitayaError>
Cluster::RPC(const string& route, protos::Request& req, protos::Response& ret)
{
    try {
        auto r = pitaya::Route(route);
        auto sv_type = r.server_type;
        auto servers = _sd->GetServersByType(sv_type);
        if (servers.size() < 1) {
            return pitaya::PitayaError(kCodeNotFound, "no servers found for route: " + route);
        }
        pitaya::Server sv = pitaya::utils::RandomServer(servers);
        return RPC(sv.id, route, req, ret);
    } catch (PitayaException* e) {
        return pitaya::PitayaError(kCodeInternalError, e->what());
    }
}

optional<PitayaError>
Cluster::RPC(const string& server_id,
             const string& route,
             protos::Request& req,
             protos::Response& ret)
{
    _log->debug("Calling RPC on server {}", server_id);
    auto sv = _sd->GetServerById(server_id);
    if (!sv) {
        // TODO better error code with constants somewhere
        return pitaya::PitayaError(kCodeNotFound, "server not found");
    }

    std::vector<uint8_t> buffer(req.ByteSizeLong());
    req.SerializeToArray(buffer.data(), buffer.size());

    // TODO proper jaeger setup
    json::value metadata;
    metadata.object();
    metadata[kPeerIdKey] = json::value::string(_server.id);
    metadata[kPeerServiceKey] = json::value::string(_server.type);
    string metadataStr = metadata.serialize();
    req.set_metadata(metadataStr);

    ret = _rpcClient->Call(sv.value(), req);
    if (ret.has_error()) {
        _log->debug("Received error calling client rpc: {}", ret.error().msg());
        return pitaya::PitayaError(ret.error().code(), ret.error().msg());
    }

    _log->debug("Successfuly called rpc: {}", ret.data());

    return boost::none;
}

} // namespace pitaya
