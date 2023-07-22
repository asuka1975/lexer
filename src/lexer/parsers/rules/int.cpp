#include "lexer/parser/rules/int.hpp"

#include <regex>
#include <memory>
#include "lexer/parser/rules/rule.hpp"
#include "lexer/parser/tokens/int.hpp"

lexer::parser::rules::Rule::SatisfiedResult lexer::parser::rules::Int::satisfied(const std::string& token) const noexcept {
    static std::regex re(R"(^([1-9]\d*|0[0-7]*|0x\d+)$)");
    return std::regex_match(token, re) ? Continue : Fail;
}

std::unique_ptr<lexer::parser::tokens::Token> lexer::parser::rules::Int::generate(char c) const {
    return std::make_unique<tokens::Int>(c, std::make_unique<Int>());
}