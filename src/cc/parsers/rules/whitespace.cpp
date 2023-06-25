#include "cc/parser/rules/whitespace.hpp"

#include <regex>

#include "cc/parser/rules/rule.hpp"
#include "cc/parser/tokens/whitespace.hpp"

cc::parser::rules::Rule::SatisfiedResult cc::parser::rules::Whitespace::satisfied(const std::string &token) const noexcept {
    static std::regex re(R"(^\s+$)");
    return std::regex_match(token, re) ? Continue : Fail;
}

std::unique_ptr<cc::parser::tokens::Token> cc::parser::rules::Whitespace::generate(char c) const {
    return std::make_unique<tokens::Whitespace>(c, std::make_unique<Whitespace>());
}