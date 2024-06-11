#include "AST/BinaryOp.hpp"
BinaryOp::BinaryOp(const uint32_t line, const uint32_t col, Op p_op,
                   std::shared_ptr<Expression> p_left, std::shared_ptr<Expression> p_right)
  : Expression{line, col, std::make_unique<Type>()}, op(p_op), lhs(std::move(p_left)),
    rhs(std::move(p_right)) {}

void BinaryOp::visitChildren(ASTNodeVisitor &p_visitor) {
  lhs->accept(p_visitor);
  rhs->accept(p_visitor);
}
#include "llvm/Support/raw_ostream.h"
std::string BinaryOp::getName() const {
  std::string ret = type->getName() + " ";
  switch (op) {
    case Op::ADD:
      ret += "+";
      break;
    case Op::SUB:
      ret += "-";
      break;
    case Op::MUL:
      ret += "*";
      break;
    case Op::DIV:
      ret += "/";
      break;
    case Op::MOD:
      ret += "%";
      break;
    case Op::AND:
      ret += "&&";
      break;
    case Op::OR:
      ret += "||";
      break;
    case Op::EQ:
      ret += "==";
      break;
    case Op::NEQ:
      ret += "!=";
      break;
    case Op::LT:
      ret += "<";
      break;
    case Op::GT:
      ret += ">";
      break;
    case Op::LEQ:
      ret += "<=";
      break;
    case Op::GEQ:
      ret += ">=";
      break;
  }
  return ret;
}