#ifndef __AST_UNARYOP_HPP
#define __AST_UNARYOP_HPP

#include "AST/Expression.hpp"
#include "visitor/AstNodeVisitor.hpp"
#include <memory>
#include <string>

class UnaryOp : public Expression {
public:
  enum class Op { NEG, NOT };
  UnaryOp(const uint32_t line, const uint32_t col, Op p_op, std::shared_ptr<Expression> p_expr);
  ~UnaryOp() = default;

  void accept(ASTNodeVisitor &v) override {
    v.visit(*this);
  };
  void visitChildren(ASTNodeVisitor &v) override;

  const std::string                  getOpName() const;
  const std::shared_ptr<Expression> &getExpr() {
    return expr;
  }

private:
  const Op                          op;
  const std::shared_ptr<Expression> expr;
};

#endif