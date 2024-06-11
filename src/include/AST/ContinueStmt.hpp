#ifndef __AST_CONTINUESTMT_HPP
#define __AST_CONTINUESTMT_HPP

#include "AST/Ast.hpp"

class ContinueStmt : public AstNode {
public:
  ContinueStmt(const uint32_t line, const uint32_t col);
  ~ContinueStmt() = default;

  void accept(ASTNodeVisitor &v) override { v.visit(*this); }
  void visitChildren(ASTNodeVisitor &v) override {}
};

#endif