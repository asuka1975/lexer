#include "cc/parser/rules/symbol.hpp"
#include "cc/parser/tokens/symbol.hpp"
#include "cc/parser/tokens/token.hpp"
#include <list>
#include <memory>

cc::parser::rules::Symbol::Symbol(std::string symbol) noexcept : m_symbol(symbol) {}

bool cc::parser::rules::Symbol::satisfied(const std::string &token) const noexcept {
    if(token.size() > m_symbol.size()) return false;

    return m_symbol.substr(0, token.size()) == token;
}

std::unique_ptr<cc::parser::tokens::Token> cc::parser::rules::Symbol::generate(char c) const {
    return std::make_unique<tokens::Symbol>(
            c, 
            std::make_unique<Symbol>(m_symbol));
}