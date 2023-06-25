#include "cc/parser/tokens/whitespace.hpp"
#include "cc/parser/tokens/token.hpp"


cc::parser::tokens::Whitespace::Whitespace(char c, std::unique_ptr<rules::Rule> rule)
    : m_value(1, c), m_rule(std::move(rule)) {}

cc::parser::tokens::TokenType cc::parser::tokens::Whitespace::type() const noexcept {
    return TokenType::Whitespace;
}

std::string cc::parser::tokens::Whitespace::value() const noexcept {
    return m_value;
}

cc::parser::tokens::Token::ValidateResult cc::parser::tokens::Whitespace::validate(char c) const noexcept {
    auto value = c ? m_value + c : m_value;
    return static_cast<ValidateResult>(m_rule->satisfied(value));
}

void cc::parser::tokens::Whitespace::add(char c) {
    m_value += c;
}
