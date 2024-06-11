#include "AST/FuncDecl.hpp"

FuncDecl::FuncDecl(uint32_t line, uint32_t col, std::string p_name,
                   std::shared_ptr<DeclStmt> p_formals, std::shared_ptr<CompoundStmt> p_body,
                   std::shared_ptr<Type> p_rt_type)
  : AstNode{line, col, AstNodeKind::FUNC_DECL}, name(p_name), formals(std::move(p_formals)), body(std::move(p_body)),
    return_type(std::move(p_rt_type)) {}

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
    const auto &params = formals->getVarDecls();
    for (size_t i = 0; i < params.size(); i++) {
      if (i)
        oss << ", ";
      oss << params[i]->getTypeName();
    }
  }
  oss << ")";
  return oss.str();
}

bool FuncDecl::checkPrototype(std::shared_ptr<std::vector<std::shared_ptr<Expression>>> args) const{
  if (!formals || !args) {
    return !formals && !args;
  }
  if (args->size() != formals->getVarDecls().size()) {
    return false;
  }
  for (size_t i = 0; i < args->size(); i++) {
    if (args->at(i)->getType()->getName() != formals->getVarDecls()[i]->getTypeName()) {
      return false;
    }
  }
  return true;
}