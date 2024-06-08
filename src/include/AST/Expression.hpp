#ifndef __AST_EXPRESSION_HPP
#define __AST_EXPRESSION_HPP

#include "AST/Ast.hpp"
class Expression : public AstNode {
  public:
    Expression(uint32_t line, uint32_t col);
    ~Expression() = default;

  protected:
    // for type checking
};

#endif