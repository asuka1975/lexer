#ifndef lexer_PARSER_TOKENS_INT_HPP
#define lexer_PARSER_TOKENS_INT_HPP

#include "lexer/parser/rules/rule.hpp"
#include "lexer/parser/tokens/token.hpp"
#include <memory>

namespace lexer::parser::tokens {
    class Int : public virtual Token {
    public:
        Int(char c, std::unique_ptr<rules::Rule> rule);
        TokenType type() const noexcept override;
        std::string value() const noexcept override;
        ValidateResult validate(char c) const noexcept override;
        void add(char c) override;
    private:
        std::string m_value;
        std::unique_ptr<rules::Rule> m_rule;
    };
}


#endif