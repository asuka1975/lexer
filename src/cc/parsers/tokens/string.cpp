#include "cc/parser/tokens/string.hpp"
#include "cc/parser/tokens/token_type.hpp"

cc::parser::tokens::String::String(char c) : m_value(1, c), prev(0) {

}

cc::parser::tokens::TokenType cc::parser::tokens::String::type() const noexcept {
    return TokenType::String;
}

std::string cc::parser::tokens::String::value() const noexcept {
    return m_value;
}

bool cc::parser::tokens::String::validate(char c) const noexcept {
    if(prev == '\\') return true;

    if((prev == '"' && (m_value.size() == 2 || m_value[m_value.size() - 2] != '\\')) || c == '\n') return false;

    return true;
}

void cc::parser::tokens::String::add(char c) {
    prev = c;
    m_value += c;
}