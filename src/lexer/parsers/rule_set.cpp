#include "lexer/parser/rule_set.hpp"

#include <memory>


lexer::parser::RuleSet::RuleSet(std::list<std::unique_ptr<rules::Rule>> rules) noexcept
    : m_rules(std::move(rules)) {}

std::list<std::unique_ptr<lexer::parser::tokens::Token>> lexer::parser::RuleSet::expects(char c) {
    std::list<std::unique_ptr<tokens::Token>> tokens;
    for (auto& rule : m_rules) {
        if (rule->satisfied(std::string(1, c)) != rules::Rule::SatisfiedResult::Fail) {
            auto expected = rule->generate(c);
            tokens.push_back(std::move(expected));
        }
    }
    return tokens;
}