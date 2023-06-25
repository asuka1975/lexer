#include "cc/parser/tokenizer.hpp"
#include "cc/parser/rule_set.hpp"
#include "cc/parser/tokens/token.hpp"
#include <list>
#include <memory>


cc::parser::Tokenizer::Tokenizer(std::unique_ptr<RuleSet> rule_set)
    : rules(std::move(rule_set)) {}

cc::parser::Tokenizer::TokenizeState cc::parser::Tokenizer::read(char c) {
    if(candidacies.empty()) {
        candidacies = rules->expects(c);
    } else if (candidacies.size() == 1) {
        // 候補が一つに絞られたとき、そのトークンのルールを満たさない文字が入力されるまで文字の受け入れを続ける
        auto& candidacy = candidacies.front();
        if(candidacy->validate(c) == tokens::Token::ValidateResult::Continue) {
            candidacy->add(c);
        } else if(candidacy->validate(c) == tokens::Token::ValidateResult::Ok) {
            candidacy->add(c);
            finishedToken = std::move(candidacy);
            candidacies.clear();
            return TokenizeState::Finish;
        } else {
            finishedToken = std::move(candidacy);
            candidacies = rules->expects(c);
            return TokenizeState::Finish;
        }
    } else {
        
        // 候補が複数あるとき、最も長いトークンのルールを満たさない文字が入力されるまで文字の受け入れを続ける
        auto it = candidacies.begin();
        std::list<std::unique_ptr<tokens::Token>> oks;

        while(it != candidacies.end()) {
            switch ((*it)->validate(c)) {
                case tokens::Token::ValidateResult::Ok:
                    ++it;
                    break;
                case tokens::Token::ValidateResult::Continue:
                    (*it)->add(c);
                    ++it;
                    break;
                case tokens::Token::ValidateResult::Fail:
                {
                    if((*it)->validate(0) == tokens::Token::ValidateResult::Ok) {
                        oks.push_back(std::move(*it));
                    }
                }
                    it = candidacies.erase(it);
                    break;
            }
        }

        if(candidacies.empty() && oks.size() == 1) {
            finishedToken = std::move(oks.front());
            candidacies = rules->expects(c);
            return TokenizeState::Finish;
        }
        if(candidacies.size() == 1 && candidacies.front()->validate(c) == tokens::Token::ValidateResult::Ok) {
            candidacies.front()->add(c);
            finishedToken = std::move(candidacies.front());
            candidacies.clear();
            return TokenizeState::Finish;
        }
    }
    return candidacies.empty() ? TokenizeState::Reject : TokenizeState::Accept;
}

std::unique_ptr<cc::parser::tokens::Token> cc::parser::Tokenizer::pop() {
    return std::move(finishedToken);
}