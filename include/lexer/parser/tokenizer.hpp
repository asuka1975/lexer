#ifndef lexer_PARSER_TOKENIZER_HPP
#define lexer_PARSER_TOKENIZER_HPP
#include <list>
#include <memory>

#include "lexer/parser/rule_set.hpp"
#include "lexer/parser/tokens/token.hpp"

namespace lexer::parser {
    class Tokenizer {
    public:
        enum class TokenizeState {
            Alexerept,
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