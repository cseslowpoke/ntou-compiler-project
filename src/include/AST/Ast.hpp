#ifndef __AST_AST_HPP
#define __AST_AST_HPP
#include <cstdint>
#include "visitor/AstNodeVisitor.hpp"
struct Location {
    int line;
    int col;
    ~Location() = default;
    Location(const std::uint32_t line, const std::uint32_t col) : line(line), col(col) {}
};


class AstNode {
  protected:
    Location loc;
  public:
    virtual ~AstNode() = default;
    AstNode(std::uint32_t line, std::uint32_t col);
    const Location &getLocation() const;
    virtual void accept(ASTNodeVisitor &v) = 0;
    virtual void visitChildren(ASTNodeVisitor &v) = 0;
};
#endif