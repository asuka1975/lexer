#ifndef lexer_PARSER_TOKENS_IDENTIFIER_HPP
#define lexer_PARSER_TOKENS_IDENTIFIER_HPP

#include "lexer/parser/tokens/token.hpp"
#include "lexer/parser/tokens/token_type.hpp"

#include "lexer/parser/rules/rule.hpp"
#include <memory>

namespace lexer::parser::tokens {
    class Identifier : public virtual Token {
    public:
        Identifier(char c, std::unique_ptr<rules::Rule> rule);
        TokenType type() const noexcept override;
        std::string value() const noexcept override;
        ValidateResult validate(char c) const noexcept override;
        void add(char c) override;
    private:
        std::string m_value;
        std::unique_ptr<rules::Rule> m_rule;
    };
}

#endif