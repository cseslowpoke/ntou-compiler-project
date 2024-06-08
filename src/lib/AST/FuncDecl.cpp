#include "AST/FuncDecl.hpp"

FuncDecl::FuncDecl(uint32_t line, uint32_t col, std::string p_name, 
    std::unique_ptr<DeclStmt> p_formals,
    std::unique_ptr<CompoundStmt> p_body,
    std::unique_ptr<Type> p_rt_type)
    : AstNode{line, col}, name(p_name), formals(std::move(p_formals)), body(std::move(p_body)), return_type(std::move(p_rt_type)){}

void FuncDecl::visitChildren(ASTNodeVisitor &v) {
  if (formals != nullptr) {
    formals->accept(v);
  }
  if (body != nullptr) {
    body->accept(v);
  }
}

std::string FuncDecl::prototype() const {
  std::ostringstream oss;
  oss << name << ' ' << return_type->getName() << "(";
  if (formals) {
    const auto &params =formals->getVarDecls();
    for (size_t i = 0; i < params.size(); i++) {
      if (i) oss << ", ";
      oss << params[i]->getTypeName();
    }
  }
  oss << ")";
  return oss.str();
}