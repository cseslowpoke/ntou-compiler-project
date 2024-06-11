#include "AST/AssignStmt.hpp"

AssignStmt::AssignStmt(uint32_t line, uint32_t col, std::shared_ptr<VarRef> p_lhs,
                       std::shared_ptr<Expression> p_rhs)
  : AstNode(line, col, AstNodeKind::ASSIGN_STMT), lhs(std::move(p_lhs)), rhs(std::move(p_rhs)) {}

void AssignStmt::visitChildren(ASTNodeVisitor &v) {
  lhs->accept(v);
  rhs->accept(v);
}