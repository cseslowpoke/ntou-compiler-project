#ifndef __AST_VARREF_HPP
#define __AST_VARREF_HPP

#include "AST/Expression.hpp"
#include "Type.hpp"
#include <memory>
#include <string>

class VarRef : public Expression {
public:
  VarRef(const uint32_t line, const uint32_t col, std::string id,
         std::shared_ptr<Type> type = nullptr);
  ~VarRef() = default;

  void accept(ASTNodeVisitor &v) override {
    v.visit(*this);
  }
  void               visitChildren(ASTNodeVisitor &v) override {}
  const std::string &getId() const {
    return id;
  }
  const std::string getTypeName() const {
    return type->getName();
  }

  void setKind(Type::Kind kind) {
    type->setKind(kind);
  }
  bool cal_dim(Type real_type);

private:
  std::string id;
  // std::unique_ptr<Type> type;
};

#endif