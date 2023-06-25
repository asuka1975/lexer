#include "cc/parser/rule_set.hpp"

#include <memory>


cc::parser::RuleSet::RuleSet(std::list<std::unique_ptr<rules::Rule>> rules) noexcept
    : m_rules(std::move(rules)) {}

std::list<std::unique_ptr<cc::parser::tokens::Token>> cc::parser::RuleSet::expects(char c) {
    std::list<std::unique_ptr<tokens::Token>> tokens;
    for (auto& rule : m_rules) {
        if (rule->satisfied(std::string(1, c))) {
            auto expected = rule->generate(c);
            tokens.push_back(std::move(expected));
        }
    }
    return tokens;
}