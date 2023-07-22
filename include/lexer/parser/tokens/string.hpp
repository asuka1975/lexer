#ifndef lexer_PARSER_TOKENS_STRING_HPP
#define lexer_PARSER_TOKENS_STRING_HPP

#include "lexer/parser/tokens/token.hpp"
#include "lexer/parser/tokens/token_type.hpp"

namespace lexer::parser::tokens {
    class String : public virtual Token {
    public:
        String(char c);
        TokenType type() const noexcept override;
        std::string value() const noexcept override;
        ValidateResult validate(char c) const noexcept override;
        void add(char c) override;
    private:
        std::string m_value;
        char prev;
    };
}

#endif