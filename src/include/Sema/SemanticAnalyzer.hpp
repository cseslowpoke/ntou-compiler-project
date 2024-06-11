#ifndef __SEMA_SEMANTICANALYZER_HPP
#define __SEMA_SEMANTICANALYZER_HPP

#include "AST/Ast.hpp"
#include "Type.hpp"
#include "visitor/AstNodeInclude.hpp"
#include "visitor/AstNodeVisitor.hpp"
#include "llvm/ADT/StringMap.h"
#include "llvm/ADT/StringRef.h"
#include <memory>

class SemanticAnalyzer final : public ASTNodeVisitor {
public:
  SemanticAnalyzer();
  ~SemanticAnalyzer() = default;
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
  bool hasErrorOccurred();

private:
  class Symbol {
  public:
    enum class Kind { Variable, Function };
    Symbol(llvm::StringRef name, Kind kind, Type type,
           std::shared_ptr<AstNode> node);
    llvm::StringRef getName() const;
    Kind getKind() const;
    Type getType() const;
    std::shared_ptr<AstNode> getNode();

  private:
    llvm::StringRef name;
    Kind kind;
    Type type;
    std::shared_ptr<AstNode> node;
  };
  class Scope {
  public:
    Scope(bool isLoop = false);
    void insert(Symbol symbol);
    bool isLoopScope();
    void setLoop(bool isLoop);
    Symbol *lookup(llvm::StringRef name);

  private:
    llvm::StringMap<Symbol> symbols;
    bool isLoop;
  };
  bool hasError;
  std::vector<Scope> scopes;
  std::shared_ptr<Type> returnType;
  Scope &currentScope();
  void pushScope(bool isLoop = false);
  void popScope();
  bool insertSymbol(Symbol symbol);
  Symbol *lookupSymbol(llvm::StringRef name);
  bool checkType(std::shared_ptr<Type> type);
  bool checkType(std::shared_ptr<Type> type1, std::shared_ptr<Type> type2);
  std::shared_ptr<Type> getType() const;
  void setType(std::shared_ptr<Type> type);
};

#endif