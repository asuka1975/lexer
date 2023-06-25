#ifndef CC_PARSER_RULE_SET_HPP
#define CC_PARSER_RULE_SET_HPP

#include <list>
#include <memory>

#include "cc/parser/rules/rule.hpp"
#include "cc/parser/tokens/token.hpp"

namespace cc::parser {
    class RuleSet {
    public:
        explicit RuleSet(std::list<std::unique_ptr<rules::Rule>> rules) noexcept;
        std::list<std::unique_ptr<tokens::Token>> expects(char c);
    private:
        std::list<std::unique_ptr<rules::Rule>> m_rules;
    };
}

#endif