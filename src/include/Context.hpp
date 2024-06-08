#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "AST/Ast.hpp"
#include "AST/Program.hpp"
#include <memory>

typedef struct Context {
  bool dumpTokens;
  bool dumpAST;
  std::unique_ptr<Program> root;
} Context;

#endif // CONTEXT_HPP