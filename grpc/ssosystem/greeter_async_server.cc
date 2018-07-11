/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "greeter_async_server.h"
  // There is no shutdown handling in this code.



  void ServerImpl::Run() {
    std::string server_address("0.0.0.0:50051");

    ServerBuilder builder;
    std::string key;
  std::string cert;
  std::string root;
std::shared_ptr<ServerCredentials> creds;
  if(enable_ssl)
  {

  read ( "server.crt", cert );
  read ( "server.key", key );
  read ( "ca.crt", root );
   grpc::SslServerCredentialsOptions::PemKeyCertPair keycert ={key,cert};
    grpc::SslServerCredentialsOptions sslOps;
    sslOps.pem_root_certs = root;
    sslOps.pem_key_cert_pairs.push_back ( keycert );
    creds = grpc::SslServerCredentials(ssl_opts);
  }else{
     sslOps=grpc::InsecureServerCredentials();
  }
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::SslServerCredentials());
    // Register "service_" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *asynchronous* service.
    builder.RegisterService(&service_);
    // Get hold of the completion queue used for the asynchronous communication
    // with the gRPC runtime.
    cq_ = builder.AddCompletionQueue();
    // Finally assemble the server.
    server_ = builder.BuildAndStart();
    std::cout << "Server listening on " << server_address << std::endl;

    // Proceed to the server's main loop.
    HandleRpcs();
  }

    ServerImpl::CallData::CallData(SSOService::AsyncService* service, ServerCompletionQueue* cq,ServiceType s_type)
        : service_(service), cq_(cq), responser_reg_(&ctx_),responder_login_(&ctx_),status_(CREATE),s_type_(s_type) {
      // Invoke the serving logic right away.
      Proceed();
    }

  void  ServerImpl::CallData::Proceed() {
      if (status_ == CREATE) {
        // Make this instance progress to the PROCESS state.
        status_ = PROCESS;
      switch (s_type_)
      case ServerImpl::CallData::S_RegisterRequest:
        service_->RequestRegister(&ctx_, &request_reg_, &responder_reg_, cq_, cq_,
                                  this);
      case ServerImpl::CallData::S_LoginRequest:
         service_->RequestLogin(&ctx_, &request_login_, &responder_login_, cq_, cq_, this);
        // As part of the initial CREATE state, we *request* that the system
        // start processing SayHello requests. In this request, "this" acts are
        // the tag uniquely identifying the request (so that different CallData
        // instances can serve different requests concurrently), in this case
        // the memory address of this CallData instance.=
      } else if (status_ == PROCESS) {
        // Spawn a new CallData instance to serve new clients while we process
        // the one for this CallData. The instance will deallocate itself as
        // part of its FINISH state.
        new CallData(service_, cq_,s_type_);

          switch (s_type_)
              case ServerImpl::CallData::S_RegisterRequest:
               //deal S_RegisterRequest
                sq->AddData(request_reg_.UserName,request_reg_.UserKey);
              case ServerImpl::CallData::S_LoginRequest:
                //deal  S_RegisterRequest
                sq->SelectKey(request_reg_.UserName);
                // And we are done! Let the gRPC runtime know we've finished, using the
                // memory address of this instance as the uniquely identifying tag for
                // the event.
                
        // responder_.Finish(reply_, Status::OK, this);
      } else {
        GPR_ASSERT(status_ == FINISH);
        // Once in the FINISH state, deallocate ourselves (CallData).
        delete this;
      }
    }

  int  ServerImpl::CallData::callback_res(bool result)override{
      responser_reg_.set_Result (result);

       status_ = FINISH;
return 0
  }

 int  ServerImpl::CallData::callback_login(bool result,int session)override{
reply_.set_LoginStatus(LOGINOK);
  reply_ .set_SessionID(session);
status_ = PROCESS;
student_response.Writer(reply_, Status::OK, this);
return 0
 }
  int  ServerImpl::CallData::callback_out(int session)override{
  reply_ .set_SessionID(session);
  reply_.set_LoginStatus(KICKOFF);
  status_ = FINISH;
  student_response.Finish(reply_, Status::OK, this);
return 0
 }

  // This can be run in multiple threads if needed.
  void  ServerImpl::HandleRpcs() {
    // Spawn a new CallData instance to serve new clients.
    new CallData(&service_, cq_.get(),CallData::S_RegisterRequest);
    new CallData(&service_, cq_.get(),CallData::S_LoginRequest);
    void* tag;  // uniquely identifies a request.
    bool ok;
    while (true) {
      // Block waiting to read the next event from the completion queue. The
      // event is uniquely identified by its tag, which in this case is the
      // memory address of a CallData instance.
      // The return value of Next should always be checked. This return value
      // tells us whether there is any kind of event or cq_ is shutting down.
      GPR_ASSERT(cq_->Next(&tag, &ok));
      GPR_ASSERT(ok);


      static_cast<CallData*>(tag)->Proceed();
    }
  }



int main(int argc, char** argv) {
  ServerImpl server;
  server.Run();
   sq->new SSOSqlite();
  return 0;
}
