#ifndef CC_PARSER_TOKENIZER_HPP
#define CC_PARSER_TOKENIZER_HPP
#include <list>
#include <memory>

#include "cc/parser/rule_set.hpp"
#include "cc/parser/tokens/token.hpp"

namespace cc::parser {
    class Tokenizer {
    public:
        enum class TokenizeState {
            Accept,
            Finish,
            Reject
        };
    public:
        Tokenizer(std::unique_ptr<RuleSet> rules);
        TokenizeState read(char c);
        std::unique_ptr<tokens::Token> pop();
    private:
        std::list<std::unique_ptr<tokens::Token>> candidacies;
        std::unique_ptr<tokens::Token> finishedToken;
        std::unique_ptr<RuleSet> rules;
    };
}

#endif