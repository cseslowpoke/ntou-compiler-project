#ifndef __AST_VARREF_HPP
#define __AST_VARREF_HPP

#include "AST/Expression.hpp"
#include "Type.hpp"
#include <string>
#include <memory>

class VarRef : public Expression {
  public:
    VarRef(const uint32_t line, const uint32_t col, std::string id);
    ~VarRef() = default;


    void accept(ASTNodeVisitor &v) override { v.visit(*this); }
    void visitChildren(ASTNodeVisitor &v) override {}

  private:
    std::string id;
    std::unique_ptr<Type> type;
};


#endif