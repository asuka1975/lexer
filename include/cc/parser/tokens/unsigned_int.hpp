#ifndef CC_PARSER_TOKENS_UNSIGNED_INT_HPP
#define CC_PARSER_TOKENS_UNSIGNED_INT_HPP

#include "cc/parser/rules/rule.hpp"
#include "cc/parser/tokens/token.hpp"
#include <memory>

namespace cc::parser::tokens {
    class UnsignedInt : public virtual Token {
    public:
        UnsignedInt(char c, std::unique_ptr<rules::Rule> rule);
        TokenType type() const noexcept override;
        std::string value() const noexcept override;
        bool validate(char c) const noexcept override;
        void add(char c) override;
    private:
        std::string m_value;
        std::unique_ptr<rules::Rule> m_rule;
    };
}

#endif