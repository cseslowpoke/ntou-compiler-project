#include "AST/AssignStmt.hpp"

AssignStmt::AssignStmt(uint32_t line, uint32_t col, std::unique_ptr<VarRef> p_lhs,
                       std::unique_ptr<Expression> p_rhs)
  : AstNode(line, col), lhs(std::move(p_lhs)), rhs(std::move(p_rhs)) {}

void AssignStmt::visitChildren(ASTNodeVisitor &v) {
  lhs->accept(v);
  rhs->accept(v);
}