#include "cc/parser/rules/whitespace.hpp"

#include <regex>

#include "cc/parser/tokens/whitespace.hpp"

bool cc::parser::rules::Whitespace::satisfied(const std::string &token) const noexcept {
    static std::regex re(R"(^\s+$)");
    return std::regex_match(token, re);
}

std::unique_ptr<cc::parser::tokens::Token> cc::parser::rules::Whitespace::generate(char c) const {
    return std::make_unique<tokens::Whitespace>(c, std::make_unique<Whitespace>());
}