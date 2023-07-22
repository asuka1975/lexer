#ifndef LEXER_PARSER_RULES_STRING_HPP
#define LEXER_PARSER_RULES_STRING_HPP

#include "lexer/parser/rules/rule.hpp"
#include "lexer/parser/tokens/token.hpp"
#include <memory>
namespace lexer::parser::rules {
    class String : public virtual Rule {
    public:
        SatisfiedResult satisfied(const std::string& token) const noexcept override;
        std::unique_ptr<tokens::Token> generate(char c) const override;
    };
}

#endif