#include "CodeGen/ToIRVisitor.hpp"

ToIRVisitor::ToIRVisitor(std::shared_ptr<llvm::Module> M)
    : M(M), Builder(M->getContext()) {
      Int32 =llvm::Type::getInt32Ty(M->getContext());
      Int1 =llvm::Type::getInt1Ty(M->getContext());
      Void =llvm::Type::getVoidTy(M->getContext());
      Float =llvm::Type::getFloatTy(M->getContext());
    }

void ToIRVisitor::visit(AssignStmt &node) {
  llvm::Value *RHS = nullptr;
  if (node.getRHS()) {
    node.getRHS()->accept(*this);
    RHS = V.get();
  }
}

void ToIRVisitor::visit(BinaryOp &node) {
  // todo
}

void ToIRVisitor::visit(BreakStmt &node) {
  // todo
}

void ToIRVisitor::visit(CompoundStmt &node) {
  // todo
}

void ToIRVisitor::visit(Constant &node) {
  // todo
}

void ToIRVisitor::visit(ContinueStmt &node) {
  // todo
}

void ToIRVisitor::visit(DeclStmt &node) {
  // todo
}

void ToIRVisitor::visit(ForStmt &node) {
  // todo
}

void ToIRVisitor::visit(FuncInv &node) {
  // todo
}

void ToIRVisitor::visit(FuncDecl &node) {
  // todo
}

void ToIRVisitor::visit(IfStmt &node) {
  // todo
}

void ToIRVisitor::visit(NullStmt &node) {
  // todo
}

void ToIRVisitor::visit(ReturnStmt &node) {
  // todo
}

void ToIRVisitor::visit(Program &node) {
  // todo
}

void ToIRVisitor::visit(UnaryOp &node) {
  // todo
}

void ToIRVisitor::visit(VarDecl &node) {
  // todo
}

void ToIRVisitor::visit(VarRef &node) {
  // todo
}

void ToIRVisitor::visit(WhileStmt &node) {
  // todo
}
