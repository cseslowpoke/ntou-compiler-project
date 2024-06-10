#ifndef __AST_CONSTANT_HPP
#define __AST_CONSTANT_HPP

#include "AST/Expression.hpp"
#include "llvm/Support/FormatVariadic.h"
#include <memory>
#include <string>
#include <variant>
class Constant : public Expression {
public:
  using ValueType = std::variant<int, float, std::string>;
  Constant(uint32_t line, uint32_t col, std::unique_ptr<ValueType> value);
  ~Constant() = default;

  void accept(ASTNodeVisitor &v) override {
    v.visit(*this);
  };
  void        visitChildren(ASTNodeVisitor &v) override;
  std::string getValueString() const;

private:
  std::unique_ptr<ValueType> _value;
};

#endif