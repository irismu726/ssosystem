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

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>
#include <thread>

#include "greeter_async_server.h"
#include "dj_toc_interface.h"
using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;
using ssosystem::SSOService;
using ssosystem::RegisterRequest;
using ssosystem::RegisterResponse;
using ssosystem::LoginRequest;
using ssosystem::LoginResponse;

enum ClientType {
      C_RegisterRequest ,
      C_LoginRequest,
};
enum{
  LOGINOK,
  LOGINERR,
  KICKOFF,
}

class SSOClient:public IDJToC {
  public:
 explicit    SSOClient ( const std::string& cert,
                  const std::string& key,
                        const std::string& root,
                        const std::string& server )
  {
    grpc::SslCredentialsOptions opts =
    {
      root,
      key,
      cert
    };

    stub_ = SSOService::NewStub ( grpc::CreateChannel (
      server, grpc::SslCredentials ( opts ) ) );
  }
    //  sends func to the server.
    void RegisterRequest(const std::string& username,::google::protobuf::int32 key) {
        // Data we are sending to the server.
        RegisterRequest request;
        request.set_username(username);
        request.set_key(key);
        request.set_token(token);

        // Call object to store rpc data
        AsyncClientCall* call = new AsyncClientCall;
        //map rpc type
        call->c_Type_ = C_RegisterRequest;

        // stub_->PrepareAsyncRegister() creates an RPC object, returning
        // an instance to store in "call" but does not actually start the RPC
        // Because we are using the asynchronous API, we need to hold on to
        // the "call" instance in order to get updates on the ongoing RPC.
        call->response_reader_reg =
            stub_->PrepareAsyncRegister(&call->context, request, &cq_);

        // StartCall initiates the RPC call
        call->response_reader_reg->StartCall();

        // Request that, upon completion of the RPC, "reply" be updated with the
        // server's response; "status" with the indication of whether the operation
        // was successful. Tag the request with the memory address of the call object.
        call->response_reader_reg->Finish(&call->reply, &call->status, (void*)call);



    }

    void LoginRequest(const std::string& username,::google::protobuf::int32 key,::google::protobuf::int32 token) {
        // Data we are sending to the server.
        RegisterRequest request;
        request.set_username(username);
        request.set_key(key);
        request.set_token(token);
        // Call object to store rpc data
        AsyncClientCall* call = new AsyncClientCall;
         call->c_Type_ = C_LoginRequest;


        // stub_->PrepareAsyncLogin() creates an RPC object, returning
        // an instance to store in "call" but does not actually start the RPC
        // Because we are using the asynchronous API, we need to hold on to
        // the "call" instance in order to get updates on the ongoing RPC.
        call->response_reader_login =
        stub_->PrepareAsyncLogin(&call->context, request, &cq_);

        // StartCall initiates the RPC call
        call->response_reader_login->StartCall();

        // Request that, upon completion of the RPC, "reply" be updated with the
        // server's response; "status" with the indication of whether the operation
        // was successful. Tag the request with the memory address of the call object.
        call->response_reader_login->Finish(&call->reply, &call->status, (void*)call);

    }

    // Loop while listening for completed responses.
    // Prints out the response from the server.
    void AsyncCompleteRpc() {
        void* got_tag;
        bool ok = false;

        // Block until the next result is available in the completion queue "cq".
        while (cq_.Next(&got_tag, &ok)) {

            // The tag in this example is the memory location of the call object
            AsyncClientCall* call = static_cast<AsyncClientCall*>(got_tag);
             GPR_ASSERT(ok);
             //deal different kind of quest
            swtich(call->c_Type_)
            case C_RegisterRequest:
            // Verify that the request was completed successfully. Note that "ok"
            // corresponds solely to the request for updates introduced by Finish().
            if (call->status.ok())
            {
              bool result = reply_reg_.Result;
               cjtodj->onregister(result);
            }
            break;
           case C_LoginRequest:
            if (call->status.ok())
            {
              int status = reply_login_.LoginStatus;
              int token = SessionID;
              if(status == LOGINOK)
              {
                 cjtodj->onregister(true);
              }
              else if(status==KICKOFF)
              {
                cjtodj->onoutsign();
              }
              }else {

                 cjtodj->onregister(false);
              }
              break;
              }
            }
          
         
            break;
            // Once we're complete, deallocate the call object.
            delete call;
            }
        }
    }
       void iregister(std::string name,int key) override{
            RegisterRequest(name,key);
       }
        void ilogin(std::string name,int key,int token) override{
            LoginRequest(name,key,token);
        }
  private:

    // struct for keeping state and data information
    struct AsyncClientCall {
        // Container for the data we expect from the server.
        RegisterResponse reply_reg_;
        LoginResponse reply_login_;
        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // Storage for the status of the RPC upon completion.
        Status status;


        std::unique_ptr<ClientAsyncResponseReader<RegisterResponse> response_reader_reg;
          std::unique_ptr<ClientAsyncResponseReader<LoginResponse> response_reader_login;

           ClientType c_Type_;
           CJToDJ*cjtodj = new CJToDJ();
    };

    // Out of the passed in Channel comes the stub, stored here, our view of the
    // server's exposed services.
    std::unique_ptr<Greeter::Stub> stub_;

    // The producer-consumer queue we use to communicate asynchronously with the
    // gRPC runtime.
    CompletionQueue cq_;
   

bool initGrpcClient() {


    // Instantiate the client. It requires a channel, out of which the actual RPCs
    // are created. This channel models a connection to an endpoint (in this case,
    // localhost at port 50051). We indicate that the channel isn't authenticated
    // (use of InsecureChannelCredentials()).

  std::string cert;
  std::string key;
  std::string root;
  std::string server { "localhost:50051" };

  read ( "client.crt", cert );
  read ( "client.key", key );
  read ( "ca.crt", root );

  SSOClient ssosys ( cert, key, root, server );
    // Spawn reader thread that loops indefinitely
  std::thread thread_ = std::thread(&SSOClient::AsyncCompleteRpc, &ssosys);

    return true;
}

};






