#include "lexer/parser/tokens/unsigned_int.hpp"
#include "lexer/parser/tokens/token.hpp"


lexer::parser::tokens::UnsignedInt::UnsignedInt(char c, std::unique_ptr<rules::Rule> rule)
    : m_value(1, c), m_rule(std::move(rule)) {}

lexer::parser::tokens::TokenType lexer::parser::tokens::UnsignedInt::type() const noexcept {
    return TokenType::UnsignedInt;
}

std::string lexer::parser::tokens::UnsignedInt::value() const noexcept {
    return m_value;
}

lexer::parser::tokens::Token::ValidateResult lexer::parser::tokens::UnsignedInt::validate(char c) const noexcept {
    auto value = c ? m_value + c : m_value;
    return static_cast<ValidateResult>(m_rule->satisfied(value));
}

void lexer::parser::tokens::UnsignedInt::add(char c) {
    m_value += c;
}