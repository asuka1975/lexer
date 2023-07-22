#include "lexer/parser/tokens/whitespace.hpp"
#include "lexer/parser/tokens/token.hpp"


lexer::parser::tokens::Whitespace::Whitespace(char c, std::unique_ptr<rules::Rule> rule)
    : m_value(1, c), m_rule(std::move(rule)) {}

lexer::parser::tokens::TokenType lexer::parser::tokens::Whitespace::type() const noexcept {
    return TokenType::Whitespace;
}

std::string lexer::parser::tokens::Whitespace::value() const noexcept {
    return m_value;
}

lexer::parser::tokens::Token::ValidateResult lexer::parser::tokens::Whitespace::validate(char c) const noexcept {
    auto value = c ? m_value + c : m_value;
    return static_cast<ValidateResult>(m_rule->satisfied(value));
}

void lexer::parser::tokens::Whitespace::add(char c) {
    m_value += c;
}
