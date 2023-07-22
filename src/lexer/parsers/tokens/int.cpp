#include "lexer/parser/tokens/int.hpp"
#include "lexer/parser/tokens/token.hpp"


lexer::parser::tokens::Int::Int(char c, std::unique_ptr<rules::Rule> rule)
    : m_value(1, c), m_rule(std::move(rule)) {}

lexer::parser::tokens::TokenType lexer::parser::tokens::Int::type() const noexcept {
    return TokenType::Int;
}

std::string lexer::parser::tokens::Int::value() const noexcept {
    return m_value;
}

lexer::parser::tokens::Token::ValidateResult lexer::parser::tokens::Int::validate(char c) const noexcept {
    auto value = c ? m_value + c : m_value;
    return static_cast<ValidateResult>(m_rule->satisfied(value));
}

void lexer::parser::tokens::Int::add(char c) {
    m_value += c;
}

