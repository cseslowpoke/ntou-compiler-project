#ifndef __CODEGEN_CODEGEN_HPP__
#define __CODEGEN_CODEGEN_HPP__

#include "AST/Ast.hpp"
#include "CodeGen/ToIRVisitor.hpp"
#include <memory>

class CodeGen {
public:
  CodeGen();
  ~CodeGen();
  void compile(std::shared_ptr<AstNode> node);
};

#endif