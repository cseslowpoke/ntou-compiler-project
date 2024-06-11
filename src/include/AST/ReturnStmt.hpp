#ifndef __AST_RETURNSTMT_HPP
#define __AST_RETURNSTMT_HPP

#include "AST/Ast.hpp"
#include "AST/Expression.hpp"
#include "Type.hpp"
#include <memory>
class ReturnStmt : public AstNode {
public:
  ReturnStmt(const uint32_t line, const uint32_t col,
             std::shared_ptr<Expression> expr);
  ~ReturnStmt() = default;

  void accept(ASTNodeVisitor &v) override { v.visit(*this); }
  void visitChildren(ASTNodeVisitor &v) override;
  const std::shared_ptr<Expression> &getReturnVal() { return returnVal; }
  Type getType() { return type; }
  void setType(Type _type) { type = _type; }

  std::shared_ptr<Expression> &getExpr() { return returnVal; }

private:
  std::shared_ptr<Expression> returnVal;
  Type type;
};
#endif