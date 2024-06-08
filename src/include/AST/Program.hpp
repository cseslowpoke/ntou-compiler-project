#ifndef __AST_PROGRAM_HPP
#define __AST_PROGRAM_HPP

#include "AST/Ast.hpp"
#include "AST/Function.hpp"
#include "visitor/AstNodeVisitor.hpp"

#include <vector>
#include <memory>
class Program : public AstNode {
  public:
    Program(uint32_t line, uint32_t col, std::unique_ptr<std::vector<std::unique_ptr<FunctionDecl>>> p_functions);
    ~Program() = default;
    std::unique_ptr<std::vector<std::unique_ptr<FunctionDecl>>> functions;
    void accept(ASTNodeVisitor &v) override {v.visit(*this); }
    void visitChildren(ASTNodeVisitor &v) override;

};
#endif