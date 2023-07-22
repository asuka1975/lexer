#ifndef lexer_PARSER_TOKENS_TOKEN_HPP
#define lexer_PARSER_TOKENS_TOKEN_HPP

#include "lexer/parser/tokens/token_type.hpp"
#include <string>
namespace lexer::parser::tokens {
    struct Token {
        enum ValidateResult {
            Ok,
            Fail,
            Continue,
        };
        virtual ~Token() = default;
        virtual TokenType type() const noexcept = 0;
        virtual std::string value() const noexcept = 0;
        virtual ValidateResult validate(char c) const noexcept = 0;
        virtual void add(char c) = 0;
    };
}

#endif