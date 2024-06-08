#ifndef __AST_ASSIGNSTMT_HPP
#define __AST_ASSIGNSTMT_HPP

#include "AST/Ast.hpp"
#include "AST/Expression.hpp"
#include "AST/VarRef.hpp"
#include "visitor/AstNodeVisitor.hpp"
#include <memory>

class AssignStmt: public AstNode {
public:
  AssignStmt(uint32_t line, uint32_t col, std::unique_ptr<VarRef> var, std::unique_ptr<Expression> value);
  ~AssignStmt() = default;

  void accept(ASTNodeVisitor &v) override {v.visit(*this);}
  void visitChildren(ASTNodeVisitor &v) override;

  // VarRef* getVar() {return var.get();}
  // Expression* getValue() {return value.get();}
  private:
    std::unique_ptr<VarRef> lhs;
    std::unique_ptr<Expression> rhs;
};

#endif