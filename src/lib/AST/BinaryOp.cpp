#include "AST/BinaryOp.hpp"

BinaryOp::BinaryOp(const uint32_t line, const uint32_t col, Op p_op, std::unique_ptr<Expression> p_left, std::unique_ptr<Expression> p_right)
    : Expression{line, col}, op(p_op), lhs(std::move(p_left)), rhs(std::move(p_right)) {}

void BinaryOp::visitChildren(ASTNodeVisitor &p_visitor) {
    lhs->accept(p_visitor);
    rhs->accept(p_visitor);
}

const std::string BinaryOp::getOpName() const {
    switch (op) {
        case Op::ADD:
            return "+";
        case Op::SUB:
            return "-";
        case Op::MUL:
            return "*";
        case Op::DIV:
            return "/";
        case Op::MOD:
            return "%";
        case Op::AND:
            return "&&";
        case Op::OR:
            return "||";
        case Op::EQ:
            return "==";
        case Op::NEQ:
            return "!=";
        case Op::LT:
            return "<";
        case Op::GT:
            return ">";
        case Op::LEQ:
            return "<=";
        case Op::GEQ:
            return ">=";
    }
    return "";
}