#include <memory>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>

#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>
#include "ssosqlite.h"
#include "ssosystem.grpc.pb.h"
#include "ISevice.h"
using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerCompletionQueue;
using grpc::Status;
using ssosystem::SSOService;
using ssosystem::RegisterRequest;
using ssosystem::RegisterResponse;
using ssosystem::LoginRequest;
using ssosystem::LoginResponse;

class ServerImpl final {
 public:
  ~ServerImpl() {
    server_->Shutdown();
    // Always shutdown the completion queue after the server.
    cq_->Shutdown();
  }

  // There is no shutdown handling in this code.
  void Run() ;

 private:
  // Class encompasing the state and logic needed to serve a request.
  class CallData  public:IService{
   public:
        enum ServiceType {
      S_RegisterRequest ,
      S_LoginRequest,
};
enum{
  LOGINOK,
  LOGINERR,
  KICKOFF,
};
    // Take in the "service" instance (in this case representing an asynchronous
    // server) and the completion queue "cq" used for asynchronous communication
    // with the gRPC runtime.
    CallData(SSOService::AsyncService* service, ServerCompletionQueue* cq,ServiceType s_type);
    void Proceed();
  int  callback_reg(bool result)override;
  int callback_login(bool result,int session)override;
  int callback_out(int session)override;
   private:
    // The means of communication with the gRPC runtime for an asynchronous
    // server.
    SSOService::AsyncService* service_;
    // The producer-consumer queue where for asynchronous server notifications.
    ServerCompletionQueue* cq_;
    // Context for the rpc, allowing to tweak aspects of it such as the use
    // of compression, authentication, as well as to send metadata back to the
    // client.
    ServerContext ctx_;

    // What we get from the client.
    RegisterRequest request_reg_;
    // What we send back to the client.
    ::ssosystem::RegisterResponse responser_reg_;
    LoginRequest  request_login_;
    // The means to get back to the client.
    LoginResponse reply_;
    ::grpc::ServerAsyncResponseWriter< ::ssosystem::LoginResponse> responder_login_;
    // Let's implement a tiny state machine with the following states.
    enum CallStatus { CREATE, PROCESS, FINISH };
    CallStatus status_;  // The current serving state.
    ServiceType s_type_;

  };

  // This can be run in multiple threads if needed.
  void HandleRpcs();

  std::unique_ptr<ServerCompletionQueue> cq_;
  SSOService::AsyncService service_;
  std::unique_ptr<Server> server_;
  SSOSqlite*sq;
};

