#ifndef CC_PARSER_TOKENS_TOKEN_HPP
#define CC_PARSER_TOKENS_TOKEN_HPP

#include "cc/parser/tokens/token_type.hpp"
#include <string>
namespace cc::parser::tokens {
    struct Token {
        virtual ~Token() = default;
        virtual TokenType type() const noexcept = 0;
        virtual std::string value() const noexcept = 0;
        virtual bool validate(char c) const noexcept = 0;
        virtual void add(char c) = 0;
    };
}

#endif