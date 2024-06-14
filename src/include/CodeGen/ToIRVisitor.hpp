#ifndef __CODEGEN_TOIRVISITOR_HPP__
#define __CODEGEN_TOIRVISITOR_HPP__

#include "visitor/AstNodeInclude.hpp"
#include "visitor/AstNodeVisitor.hpp"
#include "llvm/ADT/StringMap.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Support/raw_ostream.h"
#include <memory>

class ToIRVisitor : public ASTNodeVisitor {
  std::shared_ptr<llvm::Module> M;
  llvm::IRBuilder<> Builder;
  llvm::StringMap<llvm::Value *> NamedMap;
  std::shared_ptr<llvm::Value> V;
  llvm::Type *Int32;
  llvm::Type *Int1;
  llvm::Type *Void;
  llvm::Type *Float;

public:
  ToIRVisitor(std::shared_ptr<llvm::Module> M);
  ~ToIRVisitor() = default;
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
};

#endif