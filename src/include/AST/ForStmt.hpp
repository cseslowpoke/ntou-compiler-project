#ifndef __AST_FORSTMT_HPP
#define __AST_FORSTMT_HPP

#include "AST/Ast.hpp"
#include "AST/CompoundStmt.hpp"
#include "AST/Expression.hpp"

class ForStmt : public AstNode {
public:
  ForStmt(const uint32_t line, const uint32_t col, std::shared_ptr<AstNode> p_init,
          std::shared_ptr<Expression> p_condition, std::shared_ptr<AstNode> p_update,
          std::shared_ptr<CompoundStmt> p_body);
  ~ForStmt() = default;

  void accept(ASTNodeVisitor &v) override {
    v.visit(*this);
  }
  void visitChildren(ASTNodeVisitor &v) override;

  // const Expression *getCondition() const;
  // const Ast *getBody() const;
private:
  const std::shared_ptr<AstNode>      init;
  const std::shared_ptr<Expression>   condition;
  const std::shared_ptr<AstNode>      update;
  const std::shared_ptr<CompoundStmt> body;
};

#endif