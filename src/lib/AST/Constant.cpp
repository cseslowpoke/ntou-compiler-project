#include "AST/Constant.hpp"

Constant::Constant(uint32_t line, uint32_t col, std::unique_ptr<ValueType> value)
    : Expression(line, col), _value(std::move(value)) {}

void Constant::visitChildren(ASTNodeVisitor &v) {
    // TODO
    
}

std::string Constant::getValueString() const {
  return std::visit([](const auto& value){
    using T = std::decay_t<decltype(value)>;
    if constexpr (std::is_same_v<T, int>) {
      return llvm::formatv("int {0}", (T)value).str();
    } else if constexpr (std::is_same_v<T, float>) {
      return llvm::formatv("float {0}", (T)value).str();
    } else if constexpr (std::is_same_v<T, std::string>) {
      return llvm::formatv("char* {0}", (T)value).str();
    } else {
      return "none type";
    }
  }, *_value);
}