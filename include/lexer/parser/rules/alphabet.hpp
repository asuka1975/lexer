#ifndef LEXER_PARSER_RULES_ALPHABET_HPP
#define LEXER_PARSER_RULES_ALPHABET_HPP

#include <string>

#include "lexer/parser/rules/rule.hpp"

namespace lexer::parser::rules {
    class Alphabet : public virtual Rule {
    public:
        SatisfiedResult satisfied(const std::string& token) const noexcept override;
        std::unique_ptr<tokens::Token> generate(char c) const override;
    };
}

#endif