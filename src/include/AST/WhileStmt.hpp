#ifndef __AST_WHILESTMT_HPP
#define __AST_WHILESTMT_HPP

#include "AST/Ast.hpp"
#include "AST/CompoundStmt.hpp"
#include "AST/Expression.hpp"

#include <memory>

class WhileStmt : public AstNode {
public:
  WhileStmt(const uint32_t line, const uint32_t col,
            std::shared_ptr<Expression> p_condition,
            std::shared_ptr<CompoundStmt> p_body);
  ~WhileStmt() = default;

  void accept(ASTNodeVisitor &v) override { v.visit(*this); }
  void visitChildren(ASTNodeVisitor &v) override;

  // const Expression *getCondition() const;
  // const Ast *getBody() const;

private:
  const std::shared_ptr<Expression> condition;
  const std::shared_ptr<CompoundStmt> body;
};

#endif