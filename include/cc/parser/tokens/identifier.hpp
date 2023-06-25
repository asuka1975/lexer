#ifndef CC_PARSER_TOKENS_IDENTIFIER_HPP
#define CC_PARSER_TOKENS_IDENTIFIER_HPP

#include "cc/parser/tokens/token.hpp"
#include "cc/parser/tokens/token_type.hpp"

#include "cc/parser/rules/rule.hpp"
#include <memory>

namespace cc::parser::tokens {
    class Identifier : public virtual Token {
    public:
        Identifier(char c, std::unique_ptr<rules::Rule> rule);
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