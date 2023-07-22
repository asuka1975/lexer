
#ifndef lexer_PARSER_TOKENS_TOKEN_TYPE_HPP
#define lexer_PARSER_TOKENS_TOKEN_TYPE_HPP

namespace lexer::parser::tokens {
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