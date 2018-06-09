#include <stdlib.h>

typedef int bool;

struct Server {
  char* id;
  char* svType;
  char* metadata;
  bool frontend; };

struct SDConfig {
  char** endpoints;
  int endpointsLen;
  int etcdDialTimeoutSec;
  char* etcdPrefix;
  int heartbeatTTLSec;
  bool logHeartbeat;
  int syncServersIntervalSec;};

struct NatsRPCClientConfig {
  char* endpoint;
  int maxConnectionRetries;
  int requestTimeoutMs;};

struct NatsRPCServerConfig {
  char* endpoint;
  int maxConnectionRetries;
  int messagesBufferSize;};

struct RPCReq {
  void* data;
  int dataLen;
  char* route;
};

struct RPCRes {
  void* data;
  int dataLen;
  bool success;
};

struct Route {
  char* svType;
  char* service;
  char* method;};

typedef void* (*rpcCbFunc) (struct RPCReq);
void* bridgeFunc(rpcCbFunc f, struct RPCReq req);
