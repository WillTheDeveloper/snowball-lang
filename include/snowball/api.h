
#include "snowball.h"
#include "compiler.h"

#include <llvm-14/llvm/IR/DerivedTypes.h>
#include <map>
#include <memory>

#include <llvm/IR/Type.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/ExecutionEngine/GenericValue.h>

#ifndef __SNOWBALL_SNAPI_H_
#define __SNOWBALL_SNAPI_H_

namespace snowball {
    class SNAPI {
        public:
            SNAPI(Compiler& p_compiler) : compiler(&p_compiler) {};

            ScopeValue* create_class(std::string p_name, std::map<std::string, llvm::Type*> p_properties, std::function<void(ScopeValue*)> cb, bool is_module = false);
            ScopeValue* create_module(std::string p_name, std::map<std::string, llvm::Type*> p_properties, std::function<void(ScopeValue*)> cb);
            // ScopeValue* create_function(std::string p_name, llvm::Type* p_return_type, std::vector<std::pair<std::string, llvm::Type*>> p_args = {}, bool is_public = false);
            void create_class_method(ScopeValue* p_class, std::string p_name, llvm::Type* p_return_type, std::vector<std::pair<Type*, llvm::Type*>> p_args, std::string p_pointer = "");
            void add_to_enviroment(std::string p_name, std::unique_ptr<ScopeValue*> p_scope_value);
            
            void init_mode();
            void register_all();

            ~SNAPI() {};

            Compiler* compiler;

        private:

            bool _init_mode = false;
            std::map<ScopeValue*, std::function<void(ScopeValue*)>> _types;

            SourceInfo* _source_info;
    };
}

#endif // __SNOWBALL_SNAPI_H_
