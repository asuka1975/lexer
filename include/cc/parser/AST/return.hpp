#ifndef CC_PARSER_AST_RETURN_HPP
#define CC_PARSER_AST_RETURN_HPP


#include "component.hpp"
#include <memory>

namespace cc::parser::AST {
    class Return : public virtual Component {
    public:
        Return(std::unique_ptr<Component> expr);
        std::string compile() const override;
    private:
        std::unique_ptr<Component> expr;
    };
}

#endif