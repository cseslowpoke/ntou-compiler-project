#include "AST/Program.hpp"
#include "llvm/Support/raw_ostream.h"
Program::Program(
    uint32_t line, uint32_t col,
    std::shared_ptr<std::vector<std::shared_ptr<FuncDecl>>> p_functions)
    : AstNode(line, col, AstNodeKind::PROGRAM),
      functions(std::move(p_functions)) {}

void Program::visitChildren(ASTNodeVisitor &v) {
  for (auto &function : *functions) {
    function->accept(v);
  }
}