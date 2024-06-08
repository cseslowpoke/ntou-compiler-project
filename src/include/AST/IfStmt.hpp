#ifndef __AST_IFSTMT_HPP
#define __AST_IFSTMT_HPP

#include "AST/Ast.hpp"
#include "AST/Expression.hpp"
#include "AST/CompoundStmt.hpp"

#include <memory>

class IfStmt : public AstNode {
  public:
    IfStmt(const uint32_t line, const uint32_t col, std::unique_ptr<Expression> p_condition, std::unique_ptr<CompoundStmt> p_body, std::unique_ptr<CompoundStmt> p_else_body);
    ~IfStmt() = default;

    void accept(ASTNodeVisitor &v) override {v.visit(*this);}
    void visitChildren(ASTNodeVisitor &v) override;

    // const Expression *getCondition() const;
    // const Ast *getBody() const;
    // const Ast *getElseBody() const;

  private:
    const std::unique_ptr<Expression> condition;
    const std::unique_ptr<CompoundStmt> body;
    const std::unique_ptr<CompoundStmt> else_body;
};





#endif