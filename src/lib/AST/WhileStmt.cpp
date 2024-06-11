#include "AST/WhileStmt.hpp"

WhileStmt::WhileStmt(const uint32_t line, const uint32_t col,
                     std::shared_ptr<Expression> p_condition, std::shared_ptr<CompoundStmt> p_body)
  : AstNode(line, col, AstNodeKind::WHILE_STMT), condition(std::move(p_condition)), body(std::move(p_body)) {}

void WhileStmt::visitChildren(ASTNodeVisitor &p_visitor) {
  condition->accept(p_visitor);
  body->accept(p_visitor);
}