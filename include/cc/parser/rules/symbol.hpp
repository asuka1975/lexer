#ifndef CC_PARSER_RULES_SYMBOL_HPP
#define CC_PARSER_RULES_SYMBOL_HPP

#include "cc/parser/rules/rule.hpp"

namespace cc::parser::rules {
    class Symbol : public virtual Rule {
    public:
        Symbol(std::string symbol) noexcept;
        bool satisfied(const std::string& token) const noexcept override;
        std::unique_ptr<tokens::Token> generate(char c) const override;
    private:
        std::string m_symbol;
    };
}

#endif