#ifndef __AST_ASTDUMPER_HPP
#define __AST_ASTDUMPER_HPP



#include "visitor/AstNodeVisitor.hpp"
#include "AST/BinaryOperator.hpp"
#include "AST/BreakStmt.hpp"
#include "AST/CompoundStmt.hpp"
#include "AST/Constant.hpp"
#include "AST/ContinueStmt.hpp"
#include "AST/DeclStmt.hpp"
#include "AST/Function.hpp"
#include "AST/IfStmt.hpp"
#include "AST/NullStmt.hpp"
#include "AST/Program.hpp"
#include "AST/ReturnStmt.hpp"
#include "AST/UnaryOperator.hpp"
#include "AST/VarDecl.hpp"
#include "AST/VarRef.hpp"

class AstDumper: public ASTNodeVisitor {
  private:
    int indent = 0;
    void printIndent();
  public:
    ~AstDumper() = default;
    AstDumper() = default;
    void visit(BinaryOperator &node) override;
    void visit(BreakStmt &node) override;
    void visit(CompoundStmt &node) override;
    void visit(Constant &node) override;
    void visit(ContinueStmt &node) override;
    void visit(DeclStmt &node) override;
    void visit(FunctionDecl &node) override;
    void visit(IfStmt &node) override;
    void visit(NullStmt &node) override;
    void visit(ReturnStmt &node) override;
    void visit(Program &node) override;
    void visit(UnaryOperator &node) override;
    void visit(VarDecl &node) override;
    void visit(VarRef &node) override;
    void increaseIndent() { indent += 2;};
    void decreaseIndent() { indent -= 2;};
};
#endif