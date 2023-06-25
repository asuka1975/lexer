#include "cc/parser/tokens/symbol.hpp"
#include "cc/parser/rules/rule.hpp"
#include "cc/parser/tokens/token.hpp"
#include "cc/parser/tokens/token_type.hpp"
#include <memory>

cc::parser::tokens::Symbol::Symbol(char c, std::unique_ptr<rules::Rule> rule) : m_value(1, c), m_rule(std::move(rule)) {}

cc::parser::tokens::TokenType cc::parser::tokens::Symbol::type() const noexcept {
    return TokenType::Symbol;
}

std::string cc::parser::tokens::Symbol::value() const noexcept {
    return m_value;
}

cc::parser::tokens::Token::ValidateResult cc::parser::tokens::Symbol::validate(char c) const noexcept {
    auto value = c ? m_value + c : m_value;
    return static_cast<ValidateResult>(m_rule->satisfied(value));
}

void cc::parser::tokens::Symbol::add(char c) {
    m_value += c;
}