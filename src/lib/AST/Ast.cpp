#include "AST/Ast.hpp"
#include <cstdint>

AstNode::AstNode(uint32_t line, uint32_t col, AstNodeKind kind)
    : loc(line, col), kind(kind) {}

const Location &AstNode::getLocation() const { return loc; }