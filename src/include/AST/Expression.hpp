#ifndef __AST_EXPRESSION_HPP
#define __AST_EXPRESSION_HPP

#include "AST/Ast.hpp"
#include "Type.hpp"
#include <memory>
class Expression : public AstNode {
public:
  Expression(uint32_t line, uint32_t col, std::shared_ptr<Type> type = nullptr);
  ~Expression() = default;
  std::shared_ptr<Type> &getType() {
    return type;
  }
  void setType(std::shared_ptr<Type> _type) {
    type = std::move(_type);
  }

protected:
  std::shared_ptr<Type> type;

  // for type checking
};

#endif