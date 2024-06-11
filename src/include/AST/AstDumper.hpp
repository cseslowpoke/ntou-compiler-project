#ifndef __AST_ASTDUMPER_HPP
#define __AST_ASTDUMPER_HPP

#include "visitor/AstNodeInclude.hpp"
#include "visitor/AstNodeVisitor.hpp"

class AstDumper : public ASTNodeVisitor {
private:
  int indent = 0;
  void printIndent();

public:
  ~AstDumper() = default;
  AstDumper() = default;
  void visit(AssignStmt &node) override;
  void visit(BinaryOp &node) override;
  void visit(BreakStmt &node) override;
  void visit(CompoundStmt &node) override;
  void visit(Constant &node) override;
  void visit(ContinueStmt &node) override;
  void visit(DeclStmt &node) override;
  void visit(ForStmt &node) override;
  void visit(FuncInv &node) override;
  void visit(FuncDecl &node) override;
  void visit(IfStmt &node) override;
  void visit(NullStmt &node) override;
  void visit(ReturnStmt &node) override;
  void visit(Program &node) override;
  void visit(UnaryOp &node) override;
  void visit(VarDecl &node) override;
  void visit(VarRef &node) override;
  void visit(WhileStmt &node) override;
  void increaseIndent() { indent += 2; };
  void decreaseIndent() { indent -= 2; };
};
#endif