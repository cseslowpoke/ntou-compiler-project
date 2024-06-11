#ifndef __AST_PROGRAM_HPP
#define __AST_PROGRAM_HPP

#include "AST/Ast.hpp"
#include "AST/FuncDecl.hpp"
#include "visitor/AstNodeVisitor.hpp"

#include <memory>
#include <vector>
class Program : public AstNode {
public:
  Program(uint32_t line, uint32_t col,
          std::shared_ptr<std::vector<std::shared_ptr<FuncDecl>>> p_functions);
  ~Program() = default;
  std::shared_ptr<std::vector<std::shared_ptr<FuncDecl>>> functions;
  void                                                    accept(ASTNodeVisitor &v) override {
    v.visit(*this);
  }
  void visitChildren(ASTNodeVisitor &v) override;
};
#endif