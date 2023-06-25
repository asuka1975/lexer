#include "cc/parser/tokens/int.hpp"


cc::parser::tokens::Int::Int(char c, std::unique_ptr<rules::Rule> rule)
    : m_value(1, c), m_rule(std::move(rule)) {}

cc::parser::tokens::TokenType cc::parser::tokens::Int::type() const noexcept {
    return TokenType::Int;
}

std::string cc::parser::tokens::Int::value() const noexcept {
    return m_value;
}

bool cc::parser::tokens::Int::validate(char c) const noexcept {
    return m_rule->satisfied(m_value + c);
}

void cc::parser::tokens::Int::add(char c) {
    m_value += c;
}

