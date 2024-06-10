#include "Sema/SemanticAnalyzer.hpp"
#include "llvm/Support/raw_ostream.h"

SemanticAnalyzer::SemanticAnalyzer() {
  scopes.clear();
}
SemanticAnalyzer::Symbol::Symbol(llvm::StringRef name, Kind kind, Type type, AstNode &node)
  : name(name), kind(kind), type(type), node(node) {}

llvm::StringRef SemanticAnalyzer::Symbol::getName() const {
  return name;
}

SemanticAnalyzer::Symbol::Kind SemanticAnalyzer::Symbol::getKind() const {
  return kind;
}

Type SemanticAnalyzer::Symbol::getType() const {
  return type;
}

SemanticAnalyzer::Scope::Scope(bool isLoop) : isLoop(isLoop) {
  symbols.clear();
}

void SemanticAnalyzer::Scope::insert(Symbol symbol) {
  symbols.insert({symbol.getName(), symbol});
}

bool SemanticAnalyzer::Scope::isLoopScope() {
  return isLoop;
}

SemanticAnalyzer::Symbol *SemanticAnalyzer::Scope::lookup(llvm::StringRef name) {
  auto it = symbols.find(name);
  if (it == symbols.end()) {
    return nullptr;
  }
  return &it->second;
}

SemanticAnalyzer::Scope &SemanticAnalyzer::currentScope() {
  return scopes.back();
}

void SemanticAnalyzer::pushScope(bool isLoop) {
  scopes.push_back(Scope(isLoop));
}

void SemanticAnalyzer::popScope() {
  scopes.pop_back();
}

bool SemanticAnalyzer::insertSymbol(Symbol symbol) {
  if (currentScope().lookup(symbol.getName()) != nullptr) {
    return false;
  }
  currentScope().insert(symbol);
  return true;
}

SemanticAnalyzer::Symbol *SemanticAnalyzer::lookupSymbol(llvm::StringRef name) {
  for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
    if (auto *symbol = it->lookup(name)) {
      return symbol;
    }
  }
  return nullptr;
}

bool SemanticAnalyzer::checkType(std::unique_ptr<Type> &type) {
  return true;
}

bool SemanticAnalyzer::checkType(std::unique_ptr<Type> &type1, std::unique_ptr<Type> &type2) {
  return *type1 == *type2;
}

void SemanticAnalyzer::visit(AssignStmt &node) {
  node.visitChildren(*this);
  if (!checkType(node.getLHS()->getType(), node.getRHS()->getType())) {
    hasError = true;
    llvm::outs() << "Error: Type mismatch\n";
  }
}

void SemanticAnalyzer::visit(BinaryOp &node) {
  node.visitChildren(*this);
  if (!checkType(node.getLHS()->getType(), node.getRHS()->getType())) {
    hasError = true;
    llvm::outs() << "Error: Type mismatch\n";
  } else {
    auto type = std::make_unique<Type>(*node.getLHS()->getType());
    node.setType(std::move(type));
  }
}

void SemanticAnalyzer::visit(BreakStmt &node) {
  node.visitChildren(*this);
}

void SemanticAnalyzer::visit(CompoundStmt &node) {
  pushScope();
  node.visitChildren(*this);
  popScope();
}

void SemanticAnalyzer::visit(Constant &node) {
  node.visitChildren(*this);
}

void SemanticAnalyzer::visit(ContinueStmt &node) {
  node.visitChildren(*this);
  // todo
}

void SemanticAnalyzer::visit(DeclStmt &node) {
  node.visitChildren(*this);
}

void SemanticAnalyzer::visit(ForStmt &node) {
  node.visitChildren(*this);
}

void SemanticAnalyzer::visit(FuncInv &node) {
  node.visitChildren(*this);
  auto *symbol = lookupSymbol(node.getName());
  // todo
}

void SemanticAnalyzer::visit(FuncDecl &node) {
  node.visitChildren(*this);
  insertSymbol(Symbol(node.getName(), Symbol::Kind::Function, *node.getReturnType(), node));
}

void SemanticAnalyzer::visit(IfStmt &node) {
  node.visitChildren(*this);
  // todo
}

void SemanticAnalyzer::visit(NullStmt &node) {
  node.visitChildren(*this);
}

void SemanticAnalyzer::visit(Program &node) {
  llvm::outs() << "------ Semantic Analysis Start ------\n";
  pushScope();
  node.visitChildren(*this);
  popScope();
  if (!hasError) {
    llvm::outs() << "----- Semantic Analysis Succeed -----\n";
  }
}

void SemanticAnalyzer::visit(ReturnStmt &node) {
  node.visitChildren(*this);
}

void SemanticAnalyzer::visit(UnaryOp &node) {
  node.visitChildren(*this);
  auto type = std::make_unique<Type>(*node.getExpr()->getType());
  node.setType(std::move(type));
}

void SemanticAnalyzer::visit(VarDecl &node) {
  node.visitChildren(*this);
  if (node.getValue() && node.getValue()->getType() != node.getType()) {
    hasError = true;
    llvm::outs() << "Error: Type mismatch\n";
  }
  insertSymbol(Symbol(node.getId(), Symbol::Kind::Variable, *node.getType(), node));
}

void SemanticAnalyzer::visit(VarRef &node) {
  node.visitChildren(*this);
  auto *symbol = lookupSymbol(node.getId());
  if (symbol == nullptr) {
    hasError = true;
    llvm::outs() << "Error: Variable not decleare\n";
  }
  if (node.cal_dim(symbol->getType()) == false) {
    hasError = true;
    llvm::outs() << "Error: Array dimension mismatch\n";
  }
  node.setKind(symbol->getType().getKind());
}

void SemanticAnalyzer::visit(WhileStmt &node) {
  node.visitChildren(*this);
}

bool SemanticAnalyzer::hasErrorOccurred() {
  return hasError;
}
// Path: src/lib/Sema/SemanticAnalyzer.cpp
