#ifndef __AST_AST_HPP
#define __AST_AST_HPP
#include "visitor/AstNodeVisitor.hpp"
#include <cstdint>
struct Location {
  int line;
  int col;
  ~Location() = default;
  Location(const std::uint32_t line, const std::uint32_t col) : line(line), col(col) {}
};

class AstNode {
public: 
  enum class AstNodeKind {
    ASSIGN_STMT,
    BINARY_OP,
    BREAK_STMT,
    COMPOUND_STMT,
    CONSTANT,
    CONTINUE_STMT,
    DECL_STMT,
    EXPRESSION,
    FOR_STMT,
    FUNC_DECL,
    FUNC_INV,
    IF_STMT,
    NULL_STMT,
    PROGRAM,
    RETURN_STMT,
    UNARY_OP,
    VAR_DECL,
    VAR_REF,
    WHILE_STMT
  };
  AstNodeKind getKind() const { return kind; };
  virtual ~AstNode() = default;
  AstNode(std::uint32_t line, std::uint32_t col, AstNodeKind kind);
  const Location &getLocation() const;
  virtual void    accept(ASTNodeVisitor &v)        = 0;
  virtual void    visitChildren(ASTNodeVisitor &v) = 0;
  static bool classof(const AstNode *node) { return true; }
private:
  AstNodeKind kind;
protected:
  Location loc;
};
#endif