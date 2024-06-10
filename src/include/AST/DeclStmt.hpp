#ifndef __AST_DECLSTMT_HPP
#define __AST_DECLSTMT_HPP

#include "AST/Ast.hpp"
#include "AST/VarDecl.hpp"
#include "visitor/AstNodeVisitor.hpp"
#include <vector>

class DeclStmt : public AstNode {
private:
  std::vector<std::unique_ptr<VarDecl>> decls;

public:
  DeclStmt(uint32_t line, uint32_t col);
  ~DeclStmt() = default;

  void accept(ASTNodeVisitor &v) override {
    v.visit(*this);
  };
  void                                         visitChildren(ASTNodeVisitor &v) override;
  void                                         addVarDecl(std::unique_ptr<VarDecl> p_var);
  const std::vector<std::unique_ptr<VarDecl>> &getVarDecls() const {
    return decls;
  }
};
#endif