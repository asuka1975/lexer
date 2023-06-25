#ifndef CC_PARSER_RULES_STRING_HPP
#define CC_PARSER_RULES_STRING_HPP

#include "cc/parser/rules/rule.hpp"
#include "cc/parser/tokens/token.hpp"
#include <memory>
namespace cc::parser::rules {
    class String : public virtual Rule {
    public:
        SatisfiedResult satisfied(const std::string& token) const noexcept override;
        std::unique_ptr<tokens::Token> generate(char c) const override;
    };
}

#endif