#ifndef CC_PARSER_RULES_RULE_HPP
#define CC_PARSER_RULES_RULE_HPP

#include "cc/parser/tokens/token.hpp"

#include <list>
#include <memory>
#include <string>

namespace cc::parser::rules {
    struct Rule {
        virtual ~Rule() = default;
        virtual bool satisfied(const std::string& token) const noexcept = 0;
        virtual std::unique_ptr<tokens::Token> generate(char c) const = 0;
    };
}


#endif