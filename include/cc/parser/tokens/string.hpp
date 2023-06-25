#ifndef CC_PARSER_TOKENS_STRING_HPP
#define CC_PARSER_TOKENS_STRING_HPP

#include "cc/parser/tokens/token.hpp"
#include "cc/parser/tokens/token_type.hpp"

namespace cc::parser::tokens {
    class String : public virtual Token {
    public:
        String(char c);
        TokenType type() const noexcept override;
        std::string value() const noexcept override;
        bool validate(char c) const noexcept override;
        void add(char c) override;
    private:
        std::string m_value;
        char prev;
    };
}

#endif