#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

int main() {
  LLVMContext Context;
  Module *ModuleOb = new Module("my compiler", Context);
  IRBuilder<> Builder(Context);

  // 創建 main 函數
  FunctionType *mainFuncType = FunctionType::get(Builder.getInt32Ty(), false);
  Function *mainFunction = Function::Create(mainFuncType, Function::ExternalLinkage, "main", ModuleOb);
  BasicBlock *entry = BasicBlock::Create(Context, "entry", mainFunction);
  Builder.SetInsertPoint(entry);

  // 宣告變數
  Value *x = Builder.CreateAlloca(Builder.getInt32Ty(), nullptr, "x");
  Value *y = Builder.CreateAlloca(Builder.getInt32Ty(), nullptr, "y");
  Value *sum = Builder.CreateAlloca(Builder.getInt32Ty(), nullptr, "sum");

  // 賦值
  Builder.CreateStore(Builder.getInt32(10), x);
  Builder.CreateStore(Builder.getInt32(20), y);

  // 函數 add 的原型
  std::vector<Type *> Integers(2, Builder.getInt32Ty());
  FunctionType *funcType = FunctionType::get(Builder.getInt32Ty(), Integers, false);
  Function *addFunction = Function::Create(funcType, Function::ExternalLinkage, "add", ModuleOb);

  // 函數呼叫 add
  Value *xVal = Builder.CreateLoad(x, "xVal");
  Value *yVal = Builder.CreateLoad(y, "yVal");
  std::vector<Value *> args;
  args.push_back(xVal);
  args.push_back(yVal);
  Value *sumVal = Builder.CreateCall(addFunction, args, "sumVal");
  Builder.CreateStore(sumVal, sum);

  // printf 函數原型
  FunctionType *printfType = FunctionType::get(Builder.getInt32Ty(), true);
  Function *printfFunc = Function::Create(printfType, Function::ExternalLinkage, "printf", ModuleOb);

  // 格式化字串
  Value *formatStr = Builder.CreateGlobalStringPtr("Sum: %d\n");
  Builder.CreateCall(printfFunc, {formatStr, sumVal});

  // 返回 0
  Builder.CreateRet(Builder.getInt32(0));

  // 輸出 LLVM IR
  ModuleOb->print(outs(), nullptr);

  delete ModuleOb;
  return 0;
}
