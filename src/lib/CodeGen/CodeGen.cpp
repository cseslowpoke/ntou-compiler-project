#include "CodeGen/CodeGen.hpp"
#include "llvm/ADT/StringMap.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Support/raw_ostream.h"
CodeGen::CodeGen() {}
CodeGen::~CodeGen() {}

void CodeGen::compile(std::shared_ptr<AstNode> node) {
  llvm::LLVMContext context;
  std::shared_ptr<llvm::Module> M =
      std::make_shared<llvm::Module>("subc", context);
  ToIRVisitor ToIR(M);
  node->accept(ToIR);
  M->print(llvm::outs(), nullptr);
}