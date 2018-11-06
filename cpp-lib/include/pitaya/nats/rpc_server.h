#ifndef PITAYA_NATS_RPC_SERVER_H
#define PITAYA_NATS_RPC_SERVER_H

#include "nats/nats.h"
#include "pitaya.h"
#include "pitaya/nats/config.h"
#include "protos/request.pb.h"
#include "protos/response.pb.h"
#include "spdlog/spdlog.h"
#include <string>

namespace pitaya {
namespace nats {

class RPCServer
{
public:
    RPCServer(const pitaya::Server& server,
              const NATSConfig& config,
              pitaya::RPCHandlerFunc handler,
              const char* loggerName = nullptr);

private:
    void PrintSubStatus(natsSubscription* sub);
    static void HandleMsg(natsConnection* nc, natsSubscription* sub, natsMsg* msg, void* closure);
    static void ErrHandler(natsConnection* nc,
                           natsSubscription* subscription,
                           natsStatus err,
                           void* closure);
    static void ClosedCb(natsConnection* nc,
                         void* closure); // called when all reconnection requests failed
    static void DisconnectedCb(natsConnection* nc,
                               void* closure); // called when the connection is lost
    static void ReconnectedCb(natsConnection* nc,
                              void* closure); // called when the connection is repaired

private:
    std::shared_ptr<spdlog::logger> _log;
    static pitaya::RPCHandlerFunc handler;
    natsConnection* _nc;
    natsSubscription* _sub;
};

} // namespace nats
} // namespace pitaya

#endif // PITAYA_NATS_RPC_SERVER_H
