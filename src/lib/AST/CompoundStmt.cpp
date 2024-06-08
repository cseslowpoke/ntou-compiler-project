#include "AST/CompoundStmt.hpp"
#include "llvm/Support/raw_ostream.h"
CompoundStmt::CompoundStmt(uint32_t line, uint32_t col,         std::unique_ptr<std::vector<std::unique_ptr<DeclStmt>>> p_decls,
std::unique_ptr<std::vector<std::unique_ptr<AstNode>>> p_stmts): AstNode(line, col), decls(std::move(p_decls)), stmts(std::move(p_stmts)) {}

void CompoundStmt::visitChildren(ASTNodeVisitor &v) {
  if (decls) {
    for (auto &decl: *decls) {
      decl->accept(v);
    }
  }
  if (stmts) {
    for (auto &stmt: *stmts) {
      stmt->accept(v);
    }
  }
}