#include "AST/DeclStmt.hpp"

DeclStmt::DeclStmt(uint32_t line, uint32_t col)
    : AstNode{line, col} {}


void DeclStmt::visitChildren(ASTNodeVisitor &v) {
    for (auto &i: decls) {
        i->accept(v);
    }
}

void DeclStmt::addVarDecl(std::unique_ptr<VarDecl> p_var) {
    decls.push_back(std::move(p_var));
}