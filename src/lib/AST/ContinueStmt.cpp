#include "AST/ContinueStmt.hpp"

ContinueStmt::ContinueStmt(const uint32_t line, const uint32_t col)
    : AstNode(line, col, AstNodeKind::CONTINUE_STMT) {}