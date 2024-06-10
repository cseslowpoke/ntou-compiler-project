#ifndef __AST_VARDECL_HPP
#define __AST_VARDECL_HPP

#include "AST/Ast.hpp"
#include "AST/Expression.hpp"
#include "Type.hpp"
#include "visitor/AstNodeVisitor.hpp"
#include <memory>
#include <string>
class VarDecl : public AstNode {
public:
  VarDecl(uint32_t line, uint32_t col, std::string id, std::unique_ptr<Expression> value = nullptr);
  ~VarDecl() = default;
  void accept(ASTNodeVisitor &v) override {
    v.visit(*this);
  };
  void               visitChildren(ASTNodeVisitor &v) override;
  const std::string &getId() const {
    return id;
  }
  const std::string getTypeName() const {
    return type->getName();
  }
  void setType(std::unique_ptr<Type> _type) {
    type = std::move(_type);
  }
  std::unique_ptr<Type> &getType() {
    return type;
  };

private:
  std::string                 id;
  std::unique_ptr<Type>       type;
  std::unique_ptr<Expression> value;
};
#endif