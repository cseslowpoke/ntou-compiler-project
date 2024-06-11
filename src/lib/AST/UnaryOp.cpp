#include "AST/UnaryOp.hpp"

UnaryOp::UnaryOp(const uint32_t line, const uint32_t col, Op p_op,
                 std::shared_ptr<Expression> p_expr)
  : Expression(line, col), op(p_op), expr(std::move(p_expr)) {}

void UnaryOp::visitChildren(ASTNodeVisitor &p_visitor) {
  expr->accept(p_visitor);
}

const std::string UnaryOp::getOpName() const {
  switch (op) {
    case Op::NEG:
      return "-";
    case Op::NOT:
      return "!";
  }
  return "";
}