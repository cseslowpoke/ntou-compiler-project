#include "AST/Program.hpp"
#include "llvm/Support/raw_ostream.h"
Program::Program(uint32_t line, uint32_t col,
                 std::unique_ptr<std::vector<std::unique_ptr<FuncDecl>>> p_functions)
  : AstNode{line, col}, functions(std::move(p_functions)) {}

void Program::visitChildren(ASTNodeVisitor &v) {
  for (auto &function : *functions) {
    function->accept(v);
  }
}