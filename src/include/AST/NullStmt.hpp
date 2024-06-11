#ifndef ___AST_NULLSTMT_HPP___
#define ___AST_NULLSTMT_HPP___
#include "AST/Ast.hpp"
#include "visitor/AstNodeVisitor.hpp"
class NullStmt : public AstNode {
public:
  NullStmt(uint32_t line, uint32_t col);
  ~NullStmt() = default;

  void accept(ASTNodeVisitor &v) override { v.visit(*this); }
  void visitChildren(ASTNodeVisitor &v) override {}
};

#endif