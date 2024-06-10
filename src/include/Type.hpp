#ifndef TYPE_HPP
#define TYPE_HPP

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
    kind = _kind;
  };
  // int getDimension() {return dimension;};
  // void setDimension(int _dimension) {dimension = _dimension;};
  void addDimension(int dim) {
    arraydim.push_back(dim);
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
      default:
        break;
    }
    for (int dim : arraydim) {
      name += "[" + std::to_string(dim) + "]";
    }
    return name;
  }
  friend bool operator==(const Type &lhs, const Type &rhs) {
    return lhs.kind == rhs.kind;
  }

private:
  Kind             kind;
  std::vector<int> arraydim;
};

#endif // TYPE_HPP