#ifndef __AST_BINARYOP_HPP
#define __AST_BINARYOP_HPP

#include "AST/Expression.hpp"
#include "visitor/AstNodeVisitor.hpp"
#include <memory>
#include <string>

class BinaryOp : public Expression {
public:
  enum class Op { ADD, SUB, MUL, DIV, MOD, AND, OR, EQ, NEQ, LT, GT, LEQ, GEQ };
  BinaryOp(const uint32_t line, const uint32_t col, Op p_op, std::unique_ptr<Expression> p_left,
           std::unique_ptr<Expression> p_right);
  ~BinaryOp() = default;

  void accept(ASTNodeVisitor &v) override {
    v.visit(*this);
  };
  void                         visitChildren(ASTNodeVisitor &v) override;
  std::unique_ptr<Expression> &getLHS() {
    return lhs;
  }
  std::unique_ptr<Expression> &getRHS() {
    return rhs;
  }
  std::string getName() const;

private:
  const Op                    op;
  std::unique_ptr<Expression> lhs;
  std::unique_ptr<Expression> rhs;
};

#endif