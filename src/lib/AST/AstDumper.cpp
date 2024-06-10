#include "AST/AstDumper.hpp"
#include "llvm/Support/FormatVariadic.h"
#include "llvm/Support/raw_ostream.h"

void AstDumper::printIndent() {
  for (int i = 0; i < indent; i++) {
    llvm::outs() << " ";
  }
}

void AstDumper::visit(AssignStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("AssignStmt <line:{0}, col:{1}>\n", node.getLocation().line,
                                node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(BinaryOp &node) {
  printIndent();
  llvm::outs() << llvm::formatv("BinaryOp <line:{0}, col:{1}> {2}\n", node.getLocation().line,
                                node.getLocation().col, node.getName());
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(BreakStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("BreakStmt <line:{0}, col:{1}>\n", node.getLocation().line,
                                node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(CompoundStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("CompoundStmt <line:{0}, col:{1}>\n", node.getLocation().line,
                                node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(Constant &node) {
  printIndent();
  llvm::outs() << llvm::formatv("Constant <line:{0}, col:{1}> {2}\n", node.getLocation().line,
                                node.getLocation().col, node.getValueString());
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(ContinueStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("ContinueStmt <line:{0}, col:{1}>\n", node.getLocation().line,
                                node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(DeclStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("DeclStmt <line:{0}, col:{1}>\n", node.getLocation().line,
                                node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};

void AstDumper::visit(ForStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("ForStmt <line:{0}, col:{1}>\n", node.getLocation().line,
                                node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};

void AstDumper::visit(FuncInv &node) {
  printIndent();
  llvm::outs() << llvm::formatv("FunctionInv <line:{0}, col:{1}> {2}\n", node.getLocation().line,
                                node.getLocation().col, node.getName());
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};

void AstDumper::visit(FuncDecl &node) {
  printIndent();
  llvm::outs() << llvm::formatv("FunctionDecl <line:{0}, col:{1}> {2}\n", node.getLocation().line,
                                node.getLocation().col, node.prototype());
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(IfStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("IfStmt <line:{0}, col:{1}>\n", node.getLocation().line,
                                node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(NullStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("NullStmt <line:{0}, col:{1}>\n", node.getLocation().line,
                                node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(ReturnStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("ReturnStmt <line:{0}, col:{1}>\n", node.getLocation().line,
                                node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(Program &node) {
  // output wide same with ----- Semantic Analysis Succeed -----
  llvm::outs() << "---------- Dump Ast Start -----------\n";
  printIndent();
  llvm::outs() << llvm::formatv("Program <line:{0}, col:{1}>\n", node.getLocation().line,
                                node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
  llvm::outs() << "----------- Dump Ast End ------------\n";
};
void AstDumper::visit(UnaryOp &node) {
  printIndent();
  llvm::outs() << llvm::formatv("UnaryOp <line:{0}, col:{1}> {2}\n", node.getLocation().line,
                                node.getLocation().col, node.getOpName());
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};
void AstDumper::visit(VarDecl &node) {
  printIndent();
  llvm::outs() << llvm::formatv("VarDecl <line:{0}, col:{1}> {2} {3}\n", node.getLocation().line,
                                node.getLocation().col, node.getId(), node.getTypeName());
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};

void AstDumper::visit(VarRef &node) {
  printIndent();
  llvm::outs() << llvm::formatv("VarRef <line:{0}, col:{1}> {2} {3}\n", node.getLocation().line,
                                node.getLocation().col, node.getId(), node.getTypeName());
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};

void AstDumper::visit(WhileStmt &node) {
  printIndent();
  llvm::outs() << llvm::formatv("WhileStmt <line:{0}, col:{1}>\n", node.getLocation().line,
                                node.getLocation().col);
  increaseIndent();
  node.visitChildren(*this);
  decreaseIndent();
};