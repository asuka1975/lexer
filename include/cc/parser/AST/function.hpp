#ifndef CC_PARSER_AST_FUNCTION_HPP
#define CC_PARSER_AST_FUNCTION_HPP

#include <vector>
#include <memory>

#include "component.hpp"

namespace cc::parser::AST {
    class Function : public virtual Component {
    public:
        Function(std::unique_ptr<Component> returnType, std::string name, std::vector<std::unique_ptr<Component>> args, std::vector<std::unique_ptr<Component>> body);
        std::string compile() const override;
    private:
        std::unique_ptr<Component> returnType;
        std::string name;
        std::vector<std::unique_ptr<Component>> args;
        std::vector<std::unique_ptr<Component>> body;
    };
}


#endif