#include "lexer/parser/tokens/symbol.hpp"
#include "lexer/parser/rules/rule.hpp"
#include "lexer/parser/tokens/token.hpp"
#include "lexer/parser/tokens/token_type.hpp"
#include <memory>

lexer::parser::tokens::Symbol::Symbol(char c, std::unique_ptr<rules::Rule> rule) : m_value(1, c), m_rule(std::move(rule)) {}

lexer::parser::tokens::TokenType lexer::parser::tokens::Symbol::type() const noexcept {
    return TokenType::Symbol;
}

std::string lexer::parser::tokens::Symbol::value() const noexcept {
    return m_value;
}

lexer::parser::tokens::Token::ValidateResult lexer::parser::tokens::Symbol::validate(char c) const noexcept {
    auto value = c ? m_value + c : m_value;
    return static_cast<ValidateResult>(m_rule->satisfied(value));
}

void lexer::parser::tokens::Symbol::add(char c) {
    m_value += c;
}