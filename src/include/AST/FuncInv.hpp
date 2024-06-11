#ifndef __AST_FUNCINVOCATION_HPP
#define __AST_FUNCINVOCATION_HPP

#include "AST/Expression.hpp"
#include "visitor/AstNodeVisitor.hpp"
#include <memory>
#include <string>
#include <vector>

class FuncInv : public Expression {
public:
  FuncInv(uint32_t line, uint32_t col, std::string name,
          std::shared_ptr<std::vector<std::shared_ptr<Expression>>> args);
  ~FuncInv() = default;

const std::string &getName() const {
    return name;
  }
  const std::shared_ptr<std::vector<std::shared_ptr<Expression>>> getArgs() const { return args; }

  void accept(ASTNodeVisitor &v) override {
    v.visit(*this);
  }
  void visitChildren(ASTNodeVisitor &v) override;

private:
  std::string                                               name;
  std::shared_ptr<std::vector<std::shared_ptr<Expression>>> args;
};

#endif