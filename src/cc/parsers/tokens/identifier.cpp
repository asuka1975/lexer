#include "cc/parser/tokens/identifier.hpp"
#include "cc/parser/tokens/token.hpp"


cc::parser::tokens::Identifier::Identifier(char c, std::unique_ptr<rules::Rule> rule)
    : m_value(1, c), m_rule(std::move(rule)) {}

cc::parser::tokens::TokenType cc::parser::tokens::Identifier::type() const noexcept {
    return TokenType::Identifier;
}

std::string cc::parser::tokens::Identifier::value() const noexcept {
    return m_value;
}

cc::parser::tokens::Token::ValidateResult cc::parser::tokens::Identifier::validate(char c) const noexcept {
    auto value = c ? m_value + c : m_value;
    return static_cast<ValidateResult>(m_rule->satisfied(value));
}

void cc::parser::tokens::Identifier::add(char c) {
    m_value += c;
}
