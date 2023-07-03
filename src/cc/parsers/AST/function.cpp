#include "cc/parser/AST/function.hpp"
#include <sstream>

cc::parser::AST::Function::Function(std::unique_ptr<Component> returnType, std::string name, std::vector<std::unique_ptr<Component>> args, std::vector<std::unique_ptr<Component>> body) : returnType(std::move(returnType)), name(std::move(name)), args(std::move(args)), body(std::move(body)) {

}

std::string cc::parser::AST::Function::compile() const {
    std::ostringstream sout;
    sout << "define " << returnType->compile() << " " << " @" << name << "(";
    // join start (for copilot)
    bool first = true;
    for (const auto& arg : args) {
        if (first) {
            first = false;
        } else {
            sout << ", ";
        }
        sout << arg->compile();
    }

    sout << ") {\n";

    for (const auto& line : body) {
        sout << line->compile() << "\n";
    }

    sout << "}\n";
    return sout.str();
}