#include "cc/parser/rules/int.hpp"

#include <regex>
#include <memory>
#include "cc/parser/tokens/int.hpp"

bool cc::parser::rules::Int::satisfied(const std::string& token) const noexcept {
    static std::regex re(R"(^([1-9]\d*|0[0-7]*|0x\d+)$)");
    return std::regex_match(token, re);
}

std::unique_ptr<cc::parser::tokens::Token> cc::parser::rules::Int::generate(char c) const {
    return std::make_unique<tokens::Int>(c, std::make_unique<Int>());
}