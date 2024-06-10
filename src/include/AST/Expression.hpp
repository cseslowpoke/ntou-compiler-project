#ifndef __AST_EXPRESSION_HPP
#define __AST_EXPRESSION_HPP

#include "AST/Ast.hpp"
#include "Type.hpp"
#include <memory>
class Expression : public AstNode {
public:
  Expression(uint32_t line, uint32_t col, std::unique_ptr<Type> type = nullptr);
  ~Expression() = default;
  std::unique_ptr<Type> &getType() {
    return type;
  }
  void setType(std::unique_ptr<Type> _type) {
    type = std::move(_type);
  }

protected:
  std::unique_ptr<Type> type;

  // for type checking
};

#endif