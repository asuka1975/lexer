#ifndef CC_PARSER_AST_TYPE_HPP
#define CC_PARSER_AST_TYPE_HPP


#include "component.hpp"
#include <memory>

namespace cc::parser::AST {
    class Type : public virtual Component {
    public:
        Type(std::unique_ptr<Component> type);
        std::string compile() const override;
    private:
        std::unique_ptr<Component> type;
    };
}


#endif