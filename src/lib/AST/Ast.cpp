#include "AST/Ast.hpp"
#include <cstdint>

AstNode::AstNode(uint32_t line, uint32_t col): loc(line, col) {}
const Location &AstNode::getLocation() const { return loc; }