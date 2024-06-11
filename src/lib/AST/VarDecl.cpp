#include "AST/VarDecl.hpp"

VarDecl::VarDecl(uint32_t line, uint32_t col, std::string id, std::shared_ptr<Expression> value)
  : AstNode(line, col, AstNodeKind::VAR_DECL), id(id), value(std::move(value)) {}

void VarDecl::visitChildren(ASTNodeVisitor &v) {
  if (value) {
    value->accept(v);
  }
}