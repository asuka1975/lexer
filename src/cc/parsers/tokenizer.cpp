#include "cc/parser/tokenizer.hpp"
#include "cc/parser/rule_set.hpp"


cc::parser::Tokenizer::Tokenizer(std::unique_ptr<RuleSet> rule_set)
    : rules(std::move(rule_set)) {}

cc::parser::Tokenizer::TokenizeState cc::parser::Tokenizer::read(char c) {
    if(candidacies.empty()) {
        candidacies = rules->expects(c);
    } else if (candidacies.size() == 1) {
        // 候補が一つに絞られたとき、そのトークンのルールを満たさない文字が入力されるまで文字の受け入れを続ける
        auto& candidacy = candidacies.front();
        if(candidacy->validate(c)) {
            candidacy->add(c);
        } else {
            finishedToken = std::move(candidacy);
            candidacies = rules->expects(c);
            return TokenizeState::Finish;
        }
    } else {
        // 候補が複数あるとき、最も長いトークンのルールを満たさない文字が入力されるまで文字の受け入れを続ける
        auto it = candidacies.begin();
        while(it != candidacies.end()) {
            if((*it)->validate(c)) {
                (*it)->add(c);
                ++it;
            } else {
                it = candidacies.erase(it);
            }
        }
    }
    return candidacies.empty() ? TokenizeState::Reject : TokenizeState::Accept;
}

std::unique_ptr<cc::parser::tokens::Token> cc::parser::Tokenizer::pop() {
    return std::move(finishedToken);
}