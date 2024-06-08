#include "AST/ReturnStmt.hpp"

ReturnStmt::ReturnStmt(const uint32_t line, const uint32_t col, std::unique_ptr<Expression> returnVal)
    : AstNode{line, col}, returnVal(std::move(returnVal)) {}

void ReturnStmt::visitChildren(ASTNodeVisitor &v) {
    returnVal->accept(v);
}