#ifndef __AST_COMPOUNDSTMT_HPP
#define __AST_COMPOUNDSTMT_HPP

#include "AST/Ast.hpp"
#include "AST/DeclStmt.hpp"
#include "visitor/AstNodeVisitor.hpp"
#include <memory>
#include <vector>

class CompoundStmt : public AstNode {
private:
  std::unique_ptr<std::vector<std::unique_ptr<DeclStmt>>> decls;
  std::unique_ptr<std::vector<std::unique_ptr<AstNode>>>  stmts;

public:
  CompoundStmt(uint32_t line, uint32_t col,
               std::unique_ptr<std::vector<std::unique_ptr<DeclStmt>>> p_decls,
               std::unique_ptr<std::vector<std::unique_ptr<AstNode>>>  p_stmts);
  ~CompoundStmt() = default;

  void accept(ASTNodeVisitor &v) override {
    v.visit(*this);
  };
  void visitChildren(ASTNodeVisitor &v) override;
};
#endif