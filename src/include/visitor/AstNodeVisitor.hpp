#ifndef __VISITOR_ASTNODEVISITOR_HPP
#define __VISITOR_ASTNODEVISITOR_HPP
#include <cstdint>


class ASTNodeVisitor {

  public:
    virtual ~ASTNodeVisitor() = 0;
    virtual void visit(class BinaryOperator &node) = 0;
    virtual void visit(class BreakStmt &node) = 0;
    virtual void visit(class CompoundStmt &node) = 0;
    virtual void visit(class Constant &node) = 0;
    virtual void visit(class ContinueStmt &node) = 0;
    virtual void visit(class DeclStmt &node) = 0;
    virtual void visit(class FunctionDecl &node) = 0;
    virtual void visit(class IfStmt &node) = 0;
    virtual void visit(class NullStmt &node) = 0;
    virtual void visit(class Program &node) = 0;
    virtual void visit(class ReturnStmt &node) = 0;
    virtual void visit(class UnaryOperator &node) = 0;
    virtual void visit(class VarDecl &node) = 0;
    virtual void visit(class VarRef &node) = 0;


};
#endif