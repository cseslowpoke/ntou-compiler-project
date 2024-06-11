#include "AST/BreakStmt.hpp"

BreakStmt::BreakStmt(const uint32_t line, const uint32_t col) : AstNode{line, col, AstNodeKind::BREAK_STMT} {}