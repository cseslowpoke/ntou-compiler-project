#include "AST/Expression.hpp"

Expression::Expression(uint32_t line, uint32_t col, std::shared_ptr<Type> p_type)
  : AstNode(line, col, AstNodeKind::EXPRESSION), type(std::move(p_type)) {}
