#include <node.h>
#include "./item-object/item.cpp"
#include<iostream>
namespace demo {

  void HelloWorld(const v8::FunctionCallbackInfo<v8::Value>& args) {
    // Get the Isolate and Context from the arguments
    v8::Isolate* isolate = args.GetIsolate();
    
    Item item;
    char* mess = item.helloFromItem();
    
    item.testRapid
    
    // Create a message and return it to the JavaScript caller
    v8::Local<v8::String> hello = v8::String::NewFromUtf8(isolate, mess)
                                    .ToLocalChecked();
    args.GetReturnValue().Set(hello);
  }

  void Initialize(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "hello", HelloWorld);
  }

}  // namespace demo

NODE_MODULE(NODE_GYP_MODULE_NAME, demo::Initialize)
