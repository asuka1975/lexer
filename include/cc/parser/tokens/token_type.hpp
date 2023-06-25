
#ifndef CC_PARSER_TOKENS_TOKEN_TYPE_HPP
#define CC_PARSER_TOKENS_TOKEN_TYPE_HPP

namespace cc::parser::tokens {
    enum class TokenType {
        Symbol,
        Identifier,
        String,
        Int,
        UnsignedInt,
        Whitespace
    };
}

#endif