#include "visitor/AstDumper.hpp"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/FormatVariadic.h"



void AstDumper::printIndent() {
  for (int i = 0; i < indent; i++) {
    llvm::outs() << " ";
  }
}

void AstDumper::visit(BinaryOperator &node) {
  
};
void AstDumper::visit(BreakStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("BreakStmt <line:{0}, col:{1}>\n", node.getLocation().line, node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(CompoundStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("CompoundStmt <line:{0}, col:{1}>\n", node.getLocation().line, node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(Constant &node) {
  printIndent();
  llvm::outs() << llvm::formatv("Constant <line:{0}, col:{1}> {2}\n", node.getLocation().line, node.getLocation().col, node.getValueString());
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(ContinueStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("ContinueStmt <line:{0}, col:{1}>\n", node.getLocation().line, node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(DeclStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("DeclStmt <line:{0}, col:{1}>\n",node.getLocation().line, node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(FunctionDecl &node) {
  printIndent();
  llvm::outs() << llvm::formatv("FunctionDecl <line:{0}, col:{1}> {2}\n", node.getLocation().line, node.getLocation().col, node.prototype()); 
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(IfStmt &node) {
  
};
void AstDumper::visit(NullStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("NullStmt <line:{0}, col:{1}>\n", node.getLocation().line, node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(ReturnStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("ReturnStmt <line:{0}, col:{1}>\n", node.getLocation().line, node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(Program &node) {
  printIndent();
  llvm::outs() << llvm::formatv("Program <line:{0}, col:{1}>\n", node.getLocation().line, node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(UnaryOperator &node) {
  
};
void AstDumper::visit(VarDecl &node) {
  printIndent();
  llvm::outs() << llvm::formatv("VarDecl <line:{0}, col:{1}> {2} {3}\n", node.getLocation().line, node.getLocation().col, node.getId(), node.getTypeName());
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};

void AstDumper::visit(VarRef &node) {
  printIndent();
  // llvm::outs() << llvm::formatv("VarRef <line:{0}, col:{1}> {2} {3}\n", node.getLocation().line, node.getLocation().col, node.getId(), node.getTypeName());
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
