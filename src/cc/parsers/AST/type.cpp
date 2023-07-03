#include "cc/parser/AST/type.hpp"


cc::parser::AST::Type::Type(std::unique_ptr<Component> type) : type(std::move(type)) {

}

std::string cc::parser::AST::Type::compile() const {
    return type->compile();
}