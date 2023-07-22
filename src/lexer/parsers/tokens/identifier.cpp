#include "lexer/parser/tokens/identifier.hpp"
#include "lexer/parser/tokens/token.hpp"


lexer::parser::tokens::Identifier::Identifier(char c, std::unique_ptr<rules::Rule> rule)
    : m_value(1, c), m_rule(std::move(rule)) {}

lexer::parser::tokens::TokenType lexer::parser::tokens::Identifier::type() const noexcept {
    return TokenType::Identifier;
}

std::string lexer::parser::tokens::Identifier::value() const noexcept {
    return m_value;
}

lexer::parser::tokens::Token::ValidateResult lexer::parser::tokens::Identifier::validate(char c) const noexcept {
    auto value = c ? m_value + c : m_value;
    return static_cast<ValidateResult>(m_rule->satisfied(value));
}

void lexer::parser::tokens::Identifier::add(char c) {
    m_value += c;
}
