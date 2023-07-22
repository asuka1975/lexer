#include "lexer/parser/rules/unsigned_int.hpp"

#include <regex>

#include "lexer/parser/rules/rule.hpp"
#include "lexer/parser/tokens/unsigned_int.hpp"

lexer::parser::rules::Rule::SatisfiedResult lexer::parser::rules::UnsignedInt::satisfied(const std::string& token) const noexcept {
    static std::regex re(R"(^([1-9]\d*|0[0-7]*|0x\d+)[uU]$)");
    return std::regex_match(token, re) ? Ok : Fail;
}

std::unique_ptr<lexer::parser::tokens::Token> lexer::parser::rules::UnsignedInt::generate(char c) const {
    return std::make_unique<tokens::UnsignedInt>(c, std::make_unique<UnsignedInt>());
}