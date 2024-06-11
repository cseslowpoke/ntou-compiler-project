#include "AST/IfStmt.hpp"

IfStmt::IfStmt(const uint32_t line, const uint32_t col,
               std::shared_ptr<Expression> p_condition,
               std::shared_ptr<CompoundStmt> p_body,
               std::shared_ptr<CompoundStmt> p_else_body)
    : AstNode(line, col, AstNodeKind::IF_STMT),
      condition(std::move(p_condition)), body(std::move(p_body)),
      else_body(std::move(p_else_body)) {}

void IfStmt::visitChildren(ASTNodeVisitor &p_visitor) {
  condition->accept(p_visitor);
  body->accept(p_visitor);
  if (else_body) {
    else_body->accept(p_visitor);
  }
}