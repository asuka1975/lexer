#include "lexer/parser/rules/whitespace.hpp"

#include <regex>

#include "lexer/parser/rules/rule.hpp"
#include "lexer/parser/tokens/whitespace.hpp"

lexer::parser::rules::Rule::SatisfiedResult lexer::parser::rules::Whitespace::satisfied(const std::string &token) const noexcept {
    static std::regex re(R"(^\s+$)");
    return std::regex_match(token, re) ? Continue : Fail;
}

std::unique_ptr<lexer::parser::tokens::Token> lexer::parser::rules::Whitespace::generate(char c) const {
    return std::make_unique<tokens::Whitespace>(c, std::make_unique<Whitespace>());
}