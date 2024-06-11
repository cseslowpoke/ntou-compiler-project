#include "AST/NullStmt.hpp"

NullStmt::NullStmt(uint32_t line, uint32_t col)
    : AstNode(line, col, AstNodeKind::NULL_STMT) {}