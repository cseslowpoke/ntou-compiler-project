#ifndef __AST_IFSTMT_HPP
#define __AST_IFSTMT_HPP

#include "AST/Ast.hpp"
#include "AST/CompoundStmt.hpp"
#include "AST/Expression.hpp"

#include <memory>

class IfStmt : public AstNode {
public:
  IfStmt(const uint32_t line, const uint32_t col, std::shared_ptr<Expression> p_condition,
         std::shared_ptr<CompoundStmt> p_body, std::shared_ptr<CompoundStmt> p_else_body);
  ~IfStmt() = default;

  void accept(ASTNodeVisitor &v) override {
    v.visit(*this);
  }
  void visitChildren(ASTNodeVisitor &v) override;

  // const Expression *getCondition() const;
  // const Ast *getBody() const;
  // const Ast *getElseBody() const;

private:
  const std::shared_ptr<Expression>   condition;
  const std::shared_ptr<CompoundStmt> body;
  const std::shared_ptr<CompoundStmt> else_body;
};

#endif