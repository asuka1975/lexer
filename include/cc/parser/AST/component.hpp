#ifndef CC_PARSER_AST_COMPONENT_HPP
#define CC_PARSER_AST_COMPONENT_HPP

#include <string>

namespace cc::parser::AST {
    struct Component {
        virtual ~Component() = default;
        virtual std::string compile() const = 0;
    };
}

#endif