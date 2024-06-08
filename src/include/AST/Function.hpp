#ifndef __AST_FUNCTION_HPP
#define __AST_FUNCTION_HPP

#include "AST/Ast.hpp"
#include "AST/CompoundStmt.hpp"
#include "AST/DeclStmt.hpp"
#include "Type.hpp"
#include <vector>
#include <sstream>

class FunctionDecl : public AstNode {
  std::string name;
  std::unique_ptr<DeclStmt> formals;
  std::unique_ptr<CompoundStmt> body;
  std::unique_ptr<Type> return_type;
  public:
    FunctionDecl(uint32_t line, uint32_t col, std::string name, std::unique_ptr<DeclStmt> formals,
    std::unique_ptr<CompoundStmt> body,
    std::unique_ptr<Type> rt_type);
    ~FunctionDecl() = default;

    void accept(ASTNodeVisitor &v) override {v.visit(*this); };
    void visitChildren(ASTNodeVisitor &v) override;
    const std::string &getName() const { return name; }
    std::string prototype() const;
};


#endif