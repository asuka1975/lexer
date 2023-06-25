#include "cc/parser/rules/unsigned_int.hpp"

#include <regex>

#include "cc/parser/rules/rule.hpp"
#include "cc/parser/tokens/unsigned_int.hpp"

cc::parser::rules::Rule::SatisfiedResult cc::parser::rules::UnsignedInt::satisfied(const std::string& token) const noexcept {
    static std::regex re(R"(^([1-9]\d*|0[0-7]*|0x\d+)[uU]$)");
    return std::regex_match(token, re) ? Ok : Fail;
}

std::unique_ptr<cc::parser::tokens::Token> cc::parser::rules::UnsignedInt::generate(char c) const {
    return std::make_unique<tokens::UnsignedInt>(c, std::make_unique<UnsignedInt>());
}