#include "lexer/parser/tokens/string.hpp"
#include "lexer/parser/tokens/token.hpp"
#include "lexer/parser/tokens/token_type.hpp"

lexer::parser::tokens::String::String(char c) : m_value(1, c), prev(0) {

}

lexer::parser::tokens::TokenType lexer::parser::tokens::String::type() const noexcept {
    return TokenType::String;
}

std::string lexer::parser::tokens::String::value() const noexcept {
    return m_value;
}

lexer::parser::tokens::Token::ValidateResult lexer::parser::tokens::String::validate(char c) const noexcept {
    if(prev == '\\') return Continue;
    if(c == '"') return Ok;

    return Continue;
}

void lexer::parser::tokens::String::add(char c) {
    prev = c;
    m_value += c;
}