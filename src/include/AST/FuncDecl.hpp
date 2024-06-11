#ifndef __AST_FUNCTION_HPP
#define __AST_FUNCTION_HPP

#include "AST/Ast.hpp"
#include "AST/Expression.hpp"
#include "AST/CompoundStmt.hpp"
#include "AST/DeclStmt.hpp"
#include "Type.hpp"
#include "llvm/Support/Casting.h"
#include <sstream>
#include <vector>
#include <memory>


class FuncDecl : public AstNode {
  std::string                   name;
  std::shared_ptr<DeclStmt>     formals;
  std::shared_ptr<CompoundStmt> body;
  std::shared_ptr<Type>         return_type;

public:
  FuncDecl(uint32_t line, uint32_t col, std::string name, std::shared_ptr<DeclStmt> formals,
           std::shared_ptr<CompoundStmt> body, std::shared_ptr<Type> rt_type);
  ~FuncDecl() = default;

  void accept(ASTNodeVisitor &v) override {
    v.visit(*this);
  };
  void               visitChildren(ASTNodeVisitor &v) override;
  const std::string &getName() const {
    return name;
  }
  // gettype
  const std::shared_ptr<Type> &getReturnType() {
    return return_type;
  }
  std::string prototype() const;
  bool checkPrototype(std::shared_ptr<std::vector<std::shared_ptr<Expression>>> args) const;
  static bool classof(const AstNode *node) {
    return node->getKind() == AstNodeKind::FUNC_DECL;
  }
};

#endif