#ifndef CC_PARSER_RULES_WHITESPACE_HPP
#define CC_PARSER_RULES_WHITESPACE_HPP

#include "cc/parser/rules/rule.hpp"

namespace cc::parser::rules {
    class Whitespace : public virtual Rule {
    public:
        bool satisfied(const std::string& token) const noexcept override;
        std::unique_ptr<tokens::Token> generate(char c) const override;
    };
}


#endif