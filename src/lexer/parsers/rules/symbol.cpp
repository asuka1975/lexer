#include "lexer/parser/rules/symbol.hpp"
#include "lexer/parser/rules/rule.hpp"
#include "lexer/parser/tokens/symbol.hpp"
#include "lexer/parser/tokens/token.hpp"
#include <list>
#include <memory>

lexer::parser::rules::Symbol::Symbol(std::string symbol) noexcept : m_symbol(symbol) {}

lexer::parser::rules::Rule::SatisfiedResult lexer::parser::rules::Symbol::satisfied(const std::string &token) const noexcept {
    if(token.size() > m_symbol.size()) return Fail;

    if(m_symbol == token) return Ok;
    return m_symbol.substr(0, token.size()) == token ? Continue : Fail;
}

std::unique_ptr<lexer::parser::tokens::Token> lexer::parser::rules::Symbol::generate(char c) const {
    return std::make_unique<tokens::Symbol>(
            c, 
            std::make_unique<Symbol>(m_symbol));
}
