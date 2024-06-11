#include "AST/ForStmt.hpp"

ForStmt::ForStmt(const uint32_t line, const uint32_t col,
                 std::shared_ptr<AstNode> p_init,
                 std::shared_ptr<Expression> p_condition,
                 std::shared_ptr<AstNode> p_update,
                 std::shared_ptr<CompoundStmt> p_body)
    : AstNode(line, col, AstNodeKind::FOR_STMT), init(std::move(p_init)),
      condition(std::move(p_condition)), update(std::move(p_update)),
      body(std::move(p_body)) {}

void ForStmt::visitChildren(ASTNodeVisitor &p_visitor) {
  if (init) {
    init->accept(p_visitor);
  }
  condition->accept(p_visitor);
  if (update) {
    update->accept(p_visitor);
  }
  body->accept(p_visitor);
}