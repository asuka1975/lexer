#include "cc/parser/rule_set.hpp"
#include "cc/parser/rules/alphabet.hpp"
#include "cc/parser/rules/rule.hpp"
#include "cc/parser/rules/string.hpp"
#include "cc/parser/rules/int.hpp"
#include "cc/parser/rules/symbol.hpp"
#include "cc/parser/rules/unsigned_int.hpp"
#include "cc/parser/rules/whitespace.hpp"
#include "cc/parser/tokenizer.hpp"
#include <iostream>
#include <memory>
#include <vector>


int main() {


    std::string source = "int main() {\n"
                         "    printf(\"Hello, world\");\n"
                         "    int s = 0;\n"
                         "    for(int i = 0; i < 10; i++) {\n"
                         "        s += i;\n"
                         "    }\n"
                         "}";

    std::list<std::unique_ptr<cc::parser::rules::Rule>> rules;
    std::vector<std::string> symbols = {
            "(", ")", "{", "}", ";", ",", ":", "?",
            "+", "-", "*", "/", "%", "&", "|", "^", "~", "!",
            "=", "<", ">", ".", "[", "]", "<=", ">=", "==", "!=", "&&", 
            "||", "++", "--", "->", "<<", ">>", "<<=", ">>=",
            "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=",
    };

    rules.push_back(std::make_unique<cc::parser::rules::Alphabet>());
    rules.push_back(std::make_unique<cc::parser::rules::String>());
    rules.push_back(std::make_unique<cc::parser::rules::Int>());
    rules.push_back(std::make_unique<cc::parser::rules::UnsignedInt>());
    for(auto& symbol : symbols) {
        rules.push_back(std::make_unique<cc::parser::rules::Symbol>(symbol));
    }
    rules.push_back(std::make_unique<cc::parser::rules::Whitespace>());

    auto ruleSet = std::make_unique<cc::parser::RuleSet>(std::move(rules));
    cc::parser::Tokenizer tokenizer(std::move(ruleSet));

    for(auto c : source) {
        auto state = tokenizer.read(c);
        if(state == cc::parser::Tokenizer::TokenizeState::Finish) {
            auto token = tokenizer.pop();
            std::cout << " " << token->value() << std::endl;
        }
    }
    std::cout << "Hello, world" << std::endl;
}