#ifndef CC_PARSER_RULES_INT_HPP
#define CC_PARSER_RULES_INT_HPP

#include "cc/parser/rules/rule.hpp"

namespace cc::parser::rules {
    class Int : public virtual Rule {
    public:
        bool satisfied(const std::string& token) const noexcept override;
        std::unique_ptr<tokens::Token> generate(char c) const override;
    };
}


#endif