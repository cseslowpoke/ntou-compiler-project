#ifndef __AST_RETURNSTMT_HPP
#define __AST_RETURNSTMT_HPP

#include "AST/Ast.hpp"
#include "AST/Expression.hpp"
#include <memory>
class ReturnStmt : public AstNode {
public:
  ReturnStmt(const uint32_t line, const uint32_t col, std::unique_ptr<Expression> expr);
  ~ReturnStmt() = default;

  void accept(ASTNodeVisitor &v) override {
    v.visit(*this);
  }
  void visitChildren(ASTNodeVisitor &v) override;

  // Expression *getExpression() { return expression; }

private:
  std::unique_ptr<Expression> returnVal;
};
#endif