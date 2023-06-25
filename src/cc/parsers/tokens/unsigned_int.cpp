#include "cc/parser/tokens/unsigned_int.hpp"
#include "cc/parser/tokens/token.hpp"


cc::parser::tokens::UnsignedInt::UnsignedInt(char c, std::unique_ptr<rules::Rule> rule)
    : m_value(1, c), m_rule(std::move(rule)) {}

cc::parser::tokens::TokenType cc::parser::tokens::UnsignedInt::type() const noexcept {
    return TokenType::UnsignedInt;
}

std::string cc::parser::tokens::UnsignedInt::value() const noexcept {
    return m_value;
}

cc::parser::tokens::Token::ValidateResult cc::parser::tokens::UnsignedInt::validate(char c) const noexcept {
    auto value = c ? m_value + c : m_value;
    return static_cast<ValidateResult>(m_rule->satisfied(value));
}

void cc::parser::tokens::UnsignedInt::add(char c) {
    m_value += c;
}