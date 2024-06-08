#ifndef __AST_FORSTMT_HPP
#define __AST_FORSTMT_HPP

#include "AST/Ast.hpp"
#include "AST/Expression.hpp"
#include "AST/CompoundStmt.hpp"

class ForStmt : public AstNode {
  public:
    ForStmt(const uint32_t line, const uint32_t col, std::unique_ptr<AstNode> p_init, std::unique_ptr<Expression> p_condition, std::unique_ptr<AstNode> p_update, std::unique_ptr<CompoundStmt> p_body);
    ~ForStmt() = default;

    void accept(ASTNodeVisitor &v) override {v.visit(*this);}
    void visitChildren(ASTNodeVisitor &v) override;

    // const Expression *getCondition() const;
    // const Ast *getBody() const;
  private:
    const std::unique_ptr<AstNode> init;
    const std::unique_ptr<Expression> condition;
    const std::unique_ptr<AstNode> update;
    const std::unique_ptr<CompoundStmt> body;
};

#endif