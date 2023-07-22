#include "lexer/parser/rule_set.hpp"
#include "lexer/parser/rules/alphabet.hpp"
#include "lexer/parser/rules/rule.hpp"
#include "lexer/parser/rules/string.hpp"
#include "lexer/parser/rules/int.hpp"
#include "lexer/parser/rules/symbol.hpp"
#include "lexer/parser/rules/unsigned_int.hpp"
#include "lexer/parser/rules/whitespace.hpp"
#include "lexer/parser/tokenizer.hpp"
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
                         "    s+++++;\n"
                         "}";

    std::list<std::unique_ptr<lexer::parser::rules::Rule>> rules;
    std::vector<std::string> symbols = {
            "(", ")", "{", "}", ";", ",", ":", "?",
            "+", "-", "*", "/", "%", "&", "|", "^", "~", "!",
            "=", "<", ">", ".", "[", "]", "<=", ">=", "==", "!=", "&&", 
            "||", "++", "--", "->", "<<", ">>", "<<=", ">>=",
            "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=",
    };

    rules.push_back(std::make_unique<lexer::parser::rules::Alphabet>());
    rules.push_back(std::make_unique<lexer::parser::rules::String>());
    rules.push_back(std::make_unique<lexer::parser::rules::Int>());
    rules.push_back(std::make_unique<lexer::parser::rules::UnsignedInt>());
    for(auto& symbol : symbols) {
        rules.push_back(std::make_unique<lexer::parser::rules::Symbol>(symbol));
    }
    rules.push_back(std::make_unique<lexer::parser::rules::Whitespace>());

    auto ruleSet = std::make_unique<lexer::parser::RuleSet>(std::move(rules));
    lexer::parser::Tokenizer tokenizer(std::move(ruleSet));

    for(auto c : source) {
        auto state = tokenizer.read(c);
        if(state == lexer::parser::Tokenizer::TokenizeState::Finish) {
            auto token = tokenizer.pop();
            std::cout << " " << token->value() << std::endl;
        }
    }
    std::cout << "Hello, world" << std::endl;
}