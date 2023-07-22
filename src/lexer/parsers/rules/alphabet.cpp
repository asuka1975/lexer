#include "lexer/parser/rules/rule.hpp"
#include "lexer/parser/tokens/token.hpp"
#include <lexer/parser/rules/alphabet.hpp>
#include "lexer/parser/tokens/identifier.hpp"

#include <regex>

lexer::parser::rules::Rule::SatisfiedResult lexer::parser::rules::Alphabet::satisfied(const std::string &token) const noexcept {
    static std::regex re(R"(^[a-zA-Z_]+$)");
    return std::regex_match(token, re) ? Continue : Fail;
}

std::unique_ptr<lexer::parser::tokens::Token> lexer::parser::rules::Alphabet::generate(char c) const {
    return std::make_unique<tokens::Identifier>(c, std::make_unique<Alphabet>());
}