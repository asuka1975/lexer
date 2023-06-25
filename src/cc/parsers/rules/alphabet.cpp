#include "cc/parser/rules/rule.hpp"
#include "cc/parser/tokens/token.hpp"
#include <cc/parser/rules/alphabet.hpp>
#include "cc/parser/tokens/identifier.hpp"

#include <regex>

cc::parser::rules::Rule::SatisfiedResult cc::parser::rules::Alphabet::satisfied(const std::string &token) const noexcept {
    static std::regex re(R"(^[a-zA-Z_]+$)");
    return std::regex_match(token, re) ? Continue : Fail;
}

std::unique_ptr<cc::parser::tokens::Token> cc::parser::rules::Alphabet::generate(char c) const {
    return std::make_unique<tokens::Identifier>(c, std::make_unique<Alphabet>());
}