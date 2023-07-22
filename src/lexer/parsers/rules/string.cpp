#include "lexer/parser/rules/string.hpp"
#include "lexer/parser/rules/rule.hpp"
#include "lexer/parser/tokens/string.hpp"
#include "lexer/parser/tokens/token.hpp"
#include <memory>

lexer::parser::rules::Rule::SatisfiedResult lexer::parser::rules::String::satisfied(const std::string &token) const noexcept {
    return token == "\"" ? Continue : Fail;
}

std::unique_ptr<lexer::parser::tokens::Token> lexer::parser::rules::String::generate(char c) const {
    return std::make_unique<tokens::String>(c);
}