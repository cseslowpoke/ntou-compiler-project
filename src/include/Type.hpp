#ifndef TYPE_HPP
#define TYPE_HPP

#include "llvm/Support/raw_ostream.h"
#include <string>
#include <vector>
class Type {
public:
  enum class Kind { None, INT, VOID, CHAR, FLOAT };
  Type()  = default;
  ~Type() = default;
  Kind getKind() const {
    return kind;
  };
  void setKind(Kind _kind) {
    kind   = _kind;
    dim_1d = 1;
  };
  int &getDim1d() {
    return dim_1d;
  }
  const std::vector<int> &getArrayDim() {
    return arraydim;
  }
  // void setDimension(int _dimension) {dimension = _dimension;};
  void addDimension(int dim) {
    arraydim.push_back(dim);
    dim_1d *= dim;
  };
  std::string getName() const {
    std::string name = "";
    switch (kind) {
      case Kind::CHAR:
        name = "char";
        break;
      case Kind::FLOAT:
        name = "float";
        break;
      case Kind::INT:
        name = "int";
        break;
      case Kind::VOID:
        name = "void";
        break;
      case Kind::None:
        break;
    }
    for (int dim : arraydim) {
      name += "[" + std::to_string(dim) + "]";
    }
    return name;
  }
  friend bool operator==(const Type &lhs, const Type &rhs) {
    return lhs.kind == rhs.kind && lhs.arraydim.size() == rhs.arraydim.size();
  }
  friend bool operator!=(const Type &lhs, const Type &rhs) {
    return !(lhs == rhs);
  }
  std::vector<int> arraydim;

private:
  Kind kind;
  int  dim_1d; // for array
};

#endif // TYPE_HPP