#include "cc/parser/tokens/int.hpp"
#include "cc/parser/tokens/token.hpp"


cc::parser::tokens::Int::Int(char c, std::unique_ptr<rules::Rule> rule)
    : m_value(1, c), m_rule(std::move(rule)) {}

cc::parser::tokens::TokenType cc::parser::tokens::Int::type() const noexcept {
    return TokenType::Int;
}

std::string cc::parser::tokens::Int::value() const noexcept {
    return m_value;
}

cc::parser::tokens::Token::ValidateResult cc::parser::tokens::Int::validate(char c) const noexcept {
    auto value = c ? m_value + c : m_value;
    return static_cast<ValidateResult>(m_rule->satisfied(value));
}

void cc::parser::tokens::Int::add(char c) {
    m_value += c;
}

