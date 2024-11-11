#include <node.h>

namespace demo {

  void HelloWorld(const v8::FunctionCallbackInfo<v8::Value>& args) {
    // Get the Isolate and Context from the arguments
    v8::Isolate* isolate = args.GetIsolate();

    // Create a message and return it to the JavaScript caller
    v8::Local<v8::String> hello = v8::String::NewFromUtf8(isolate, "Hello, World from C++!")
                                    .ToLocalChecked();
    args.GetReturnValue().Set(hello);
  }

  void Initialize(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "hello", HelloWorld);
  }

}  // namespace demo

NODE_MODULE(NODE_GYP_MODULE_NAME, demo::Initialize)
