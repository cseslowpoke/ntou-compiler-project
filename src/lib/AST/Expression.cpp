#include "AST/Expression.hpp"

Expression::Expression(uint32_t line, uint32_t col, std::unique_ptr<Type> p_type)
  : AstNode{line, col}, type(std::move(p_type)) {}
