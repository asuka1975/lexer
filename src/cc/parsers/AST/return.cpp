#include "cc/parser/AST/return.hpp"


cc::parser::AST::Return::Return(std::unique_ptr<Component> expr) : expr(std::move(expr)) {

}

std::string cc::parser::AST::Return::compile() const {
    return "ret " + expr->compile();
}