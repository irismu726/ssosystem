// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: ssosystem.proto
// Original file comments:
// Copyright 2015 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef GRPC_ssosystem_2eproto__INCLUDED
#define GRPC_ssosystem_2eproto__INCLUDED

#include "ssosystem.pb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace ssosystem {

class SSOService final {
 public:
  static constexpr char const* service_full_name() {
    return "ssosystem.SSOService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Register(::grpc::ClientContext* context, const ::ssosystem::RegisterRequest& request, ::ssosystem::RegisterResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::ssosystem::RegisterResponse>> AsyncRegister(::grpc::ClientContext* context, const ::ssosystem::RegisterRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::ssosystem::RegisterResponse>>(AsyncRegisterRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::ssosystem::RegisterResponse>> PrepareAsyncRegister(::grpc::ClientContext* context, const ::ssosystem::RegisterRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::ssosystem::RegisterResponse>>(PrepareAsyncRegisterRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderInterface< ::ssosystem::LoginResponse>> Login(::grpc::ClientContext* context, const ::ssosystem::LoginRequest& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::ssosystem::LoginResponse>>(LoginRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::ssosystem::LoginResponse>> AsyncLogin(::grpc::ClientContext* context, const ::ssosystem::LoginRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::ssosystem::LoginResponse>>(AsyncLoginRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::ssosystem::LoginResponse>> PrepareAsyncLogin(::grpc::ClientContext* context, const ::ssosystem::LoginRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::ssosystem::LoginResponse>>(PrepareAsyncLoginRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::ssosystem::RegisterResponse>* AsyncRegisterRaw(::grpc::ClientContext* context, const ::ssosystem::RegisterRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::ssosystem::RegisterResponse>* PrepareAsyncRegisterRaw(::grpc::ClientContext* context, const ::ssosystem::RegisterRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderInterface< ::ssosystem::LoginResponse>* LoginRaw(::grpc::ClientContext* context, const ::ssosystem::LoginRequest& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::ssosystem::LoginResponse>* AsyncLoginRaw(::grpc::ClientContext* context, const ::ssosystem::LoginRequest& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::ssosystem::LoginResponse>* PrepareAsyncLoginRaw(::grpc::ClientContext* context, const ::ssosystem::LoginRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Register(::grpc::ClientContext* context, const ::ssosystem::RegisterRequest& request, ::ssosystem::RegisterResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::ssosystem::RegisterResponse>> AsyncRegister(::grpc::ClientContext* context, const ::ssosystem::RegisterRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::ssosystem::RegisterResponse>>(AsyncRegisterRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::ssosystem::RegisterResponse>> PrepareAsyncRegister(::grpc::ClientContext* context, const ::ssosystem::RegisterRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::ssosystem::RegisterResponse>>(PrepareAsyncRegisterRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReader< ::ssosystem::LoginResponse>> Login(::grpc::ClientContext* context, const ::ssosystem::LoginRequest& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::ssosystem::LoginResponse>>(LoginRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::ssosystem::LoginResponse>> AsyncLogin(::grpc::ClientContext* context, const ::ssosystem::LoginRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::ssosystem::LoginResponse>>(AsyncLoginRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::ssosystem::LoginResponse>> PrepareAsyncLogin(::grpc::ClientContext* context, const ::ssosystem::LoginRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::ssosystem::LoginResponse>>(PrepareAsyncLoginRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::ssosystem::RegisterResponse>* AsyncRegisterRaw(::grpc::ClientContext* context, const ::ssosystem::RegisterRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::ssosystem::RegisterResponse>* PrepareAsyncRegisterRaw(::grpc::ClientContext* context, const ::ssosystem::RegisterRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReader< ::ssosystem::LoginResponse>* LoginRaw(::grpc::ClientContext* context, const ::ssosystem::LoginRequest& request) override;
    ::grpc::ClientAsyncReader< ::ssosystem::LoginResponse>* AsyncLoginRaw(::grpc::ClientContext* context, const ::ssosystem::LoginRequest& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::ssosystem::LoginResponse>* PrepareAsyncLoginRaw(::grpc::ClientContext* context, const ::ssosystem::LoginRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Register_;
    const ::grpc::internal::RpcMethod rpcmethod_Login_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Register(::grpc::ServerContext* context, const ::ssosystem::RegisterRequest* request, ::ssosystem::RegisterResponse* response);
    virtual ::grpc::Status Login(::grpc::ServerContext* context, const ::ssosystem::LoginRequest* request, ::grpc::ServerWriter< ::ssosystem::LoginResponse>* writer);
  };
  template <class BaseClass>
  class WithAsyncMethod_Register : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Register() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Register() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Register(::grpc::ServerContext* context, const ::ssosystem::RegisterRequest* request, ::ssosystem::RegisterResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRegister(::grpc::ServerContext* context, ::ssosystem::RegisterRequest* request, ::grpc::ServerAsyncResponseWriter< ::ssosystem::RegisterResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_Login : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Login() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_Login() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Login(::grpc::ServerContext* context, const ::ssosystem::LoginRequest* request, ::grpc::ServerWriter< ::ssosystem::LoginResponse>* writer) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestLogin(::grpc::ServerContext* context, ::ssosystem::LoginRequest* request, ::grpc::ServerAsyncWriter< ::ssosystem::LoginResponse>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Register<WithAsyncMethod_Login<Service > > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_Register : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Register() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Register() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Register(::grpc::ServerContext* context, const ::ssosystem::RegisterRequest* request, ::ssosystem::RegisterResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_Login : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Login() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_Login() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Login(::grpc::ServerContext* context, const ::ssosystem::LoginRequest* request, ::grpc::ServerWriter< ::ssosystem::LoginResponse>* writer) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Register : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_Register() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::ssosystem::RegisterRequest, ::ssosystem::RegisterResponse>(std::bind(&WithStreamedUnaryMethod_Register<BaseClass>::StreamedRegister, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_Register() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Register(::grpc::ServerContext* context, const ::ssosystem::RegisterRequest* request, ::ssosystem::RegisterResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedRegister(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::ssosystem::RegisterRequest,::ssosystem::RegisterResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Register<Service > StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_Login : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithSplitStreamingMethod_Login() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::SplitServerStreamingHandler< ::ssosystem::LoginRequest, ::ssosystem::LoginResponse>(std::bind(&WithSplitStreamingMethod_Login<BaseClass>::StreamedLogin, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithSplitStreamingMethod_Login() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Login(::grpc::ServerContext* context, const ::ssosystem::LoginRequest* request, ::grpc::ServerWriter< ::ssosystem::LoginResponse>* writer) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedLogin(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::ssosystem::LoginRequest,::ssosystem::LoginResponse>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_Login<Service > SplitStreamedService;
  typedef WithStreamedUnaryMethod_Register<WithSplitStreamingMethod_Login<Service > > StreamedService;
};

}  // namespace ssosystem


#endif  // GRPC_ssosystem_2eproto__INCLUDED
