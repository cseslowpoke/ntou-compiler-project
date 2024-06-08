#ifndef __AST_BREAKSTMT_HPP
#define __AST_BREAKSTMT_HPP

#include "AST/Ast.hpp"

class BreakStmt : public AstNode {
  public:
    BreakStmt(const uint32_t line, const uint32_t col);
    ~BreakStmt() = default;

    void accept(ASTNodeVisitor &v) override {v.visit(*this);}
    void visitChildren(ASTNodeVisitor &v) override {}
};
#endif