#ifndef LEXER_PARSER_RULES_WHITESPACE_HPP
#define LEXER_PARSER_RULES_WHITESPACE_HPP

#include "lexer/parser/rules/rule.hpp"

namespace lexer::parser::rules {
    class Whitespace : public virtual Rule {
    public:
        SatisfiedResult satisfied(const std::string& token) const noexcept override;
        std::unique_ptr<tokens::Token> generate(char c) const override;
    };
}


#endif