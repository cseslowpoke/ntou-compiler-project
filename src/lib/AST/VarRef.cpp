#include "AST/VarRef.hpp"

VarRef::VarRef(uint32_t line, uint32_t col, std::string p_id, std::shared_ptr<Type> p_type)
  : Expression(line, col, std::move(p_type)), id(p_id) {}

bool VarRef::cal_dim(Type real_type) {
  if (real_type.getArrayDim().size() != type->getArrayDim().size()) {
    return false;
  }
  int                    &dim      = type->getDim1d();
  const std::vector<int> &array_   = type->getArrayDim();
  const std::vector<int> &real_dim = real_type.getArrayDim();
  dim                              = array_[0];
  for (int i = 1; i < array_.size(); i++) {
    dim += array_[i] * real_dim[i - 1];
  }
  type->arraydim.clear();
  return true;
}