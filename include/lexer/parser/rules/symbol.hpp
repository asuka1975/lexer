#ifndef LEXER_PARSER_RULES_SYMBOL_HPP
#define LEXER_PARSER_RULES_SYMBOL_HPP

#include "lexer/parser/rules/rule.hpp"

namespace lexer::parser::rules {
    class Symbol : public virtual Rule {
    public:
        Symbol(std::string symbol) noexcept;
        SatisfiedResult satisfied(const std::string& token) const noexcept override;
        std::unique_ptr<tokens::Token> generate(char c) const override;
    private:
        std::string m_symbol;
    };
}

#endif