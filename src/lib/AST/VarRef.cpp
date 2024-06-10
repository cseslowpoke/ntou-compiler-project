#include "AST/VarRef.hpp"

VarRef::VarRef(uint32_t line, uint32_t col, std::string p_id, std::unique_ptr<Type> p_type)
  : Expression(line, col, std::move(p_type)), id(p_id) {}