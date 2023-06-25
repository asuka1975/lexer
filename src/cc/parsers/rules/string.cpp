#include "cc/parser/rules/string.hpp"
#include "cc/parser/tokens/string.hpp"
#include "cc/parser/tokens/token.hpp"
#include <memory>

bool cc::parser::rules::String::satisfied(const std::string &token) const noexcept {
    return token == "\"";
}

std::unique_ptr<cc::parser::tokens::Token> cc::parser::rules::String::generate(char c) const {
    return std::make_unique<tokens::String>(c);
}