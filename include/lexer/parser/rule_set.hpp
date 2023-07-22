#ifndef lexer_PARSER_RULE_SET_HPP
#define lexer_PARSER_RULE_SET_HPP

#include <list>
#include <memory>

#include "lexer/parser/rules/rule.hpp"
#include "lexer/parser/tokens/token.hpp"

namespace lexer::parser {
    class RuleSet {
    public:
        explicit RuleSet(std::list<std::unique_ptr<rules::Rule>> rules) noexcept;
        std::list<std::unique_ptr<tokens::Token>> expects(char c);
    private:
        std::list<std::unique_ptr<rules::Rule>> m_rules;
    };
}

#endif