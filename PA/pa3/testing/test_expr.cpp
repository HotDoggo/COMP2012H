#include "expression.h"
#include <iostream>
#include <string>

enum class TestType {
  eval,
  as_string,
};
// Test LitExpr
template <typename T, TestType type>
void test_LitExpr(T val) {
  std::cout << "==== Test on LitExpr ====" << std::endl;
  std::cout << "Value: " << val << std::endl;
  LitExpr<T> lit(val);
  if (type == TestType::as_string) {
    std::cout << "Lit_str: " << lit.as_string() << std::endl;
  } else {
    std::cout << "Lit_val: " << lit.eval() << std::endl;
  }

  std::cout << std::endl;
}

// Test UnOpExpr
template <typename T, UnOp op, TestType type>
void test_UnOpExpr(Expr<T>* operand) {
  std::string op_str;
  switch (op) {
    case UnOp::pos:
      op_str = "Pos";
      break;
    case UnOp::neg:
      op_str = "Neg";
      break;
  }
  std::cout << "==== Test on " << op_str << "Expr ====" << std::endl;

  if (type == TestType::as_string) {
    std::cout << "Operand_str: " << operand->as_string()
                << std::endl;
  } else {
    std::cout << "Operand_val: " << operand->eval() << std::endl;
  }

  UnOpExpr<T, op> unop(operand);
  if (type == TestType::as_string) {
    std::cout << op_str << "_str: " << unop.as_string() << std::endl;
  } else {
    std::cout << op_str << "_val: " << unop.eval() << std::endl;
  }
  std::cout << std::endl;
}

// Test BinOpExpr
template <typename T, BinOp op, TestType type>
void test_BinOpExpr(Expr<T> *lhs, Expr<T> *rhs) {
  std::string op_str;
  switch (op) {
  case BinOp::add:
    op_str = "Add";
    break;
  case BinOp::sub:
    op_str = "Sub";
    break;
  case BinOp::mul:
    op_str = "Mul";
    break;
  case BinOp::div:
    op_str = "Div";
    break;
  }
  std::cout << "==== Test on " << op_str << "Expr ====" << std::endl;

  if (type == TestType::as_string) {
    std::cout << "lhs_str: " << lhs->as_string() << "       ";
    std::cout << "rhs_str: " << rhs->as_string() << std::endl;
  } else {
    std::cout << "lhs_val: " << lhs->eval() << "       ";
    std::cout << "rhs_val: " << rhs->eval() << std::endl;
  }

  BinOpExpr<T, op> binop(lhs, rhs);
  if (type == TestType::as_string) {
    std::cout << op_str << "_str: " << binop.as_string() << std::endl;
  } else {
    std::cout << op_str << "_val: " << binop.eval() << std::endl;
  }
  std::cout << std::endl;
}


int main() {
  int test_case;
  std::cin >> test_case;
  switch (test_case) {
  case 1:
    test_LitExpr<float, TestType::as_string>(3.141592653589793);
    break;
  case 2:
    test_LitExpr<float, TestType::eval>(3.141592653589793);
    break;
  case 3: {
    LitExpr<float> *lit = new LitExpr<float>(20.12);
    test_UnOpExpr<float, UnOp::pos, TestType::as_string>(lit);
  } break;
  case 4: {
    LitExpr<float> *lit = new LitExpr<float>(20.12);
    test_UnOpExpr<float, UnOp::pos, TestType::eval>(lit);
  } break;
  case 5: {
    LitExpr<float> *lit = new LitExpr<float>(20.12);
    test_UnOpExpr<float, UnOp::neg, TestType::as_string>(lit);
  } break;
  case 6: {
    LitExpr<float> *lit = new LitExpr<float>(20.12);
    test_UnOpExpr<float, UnOp::neg, TestType::eval>(lit);
  } break;
  case 7: {
    LitExpr<float> *lit1 = new LitExpr<float>(20.23);
    LitExpr<float> *lit2 = new LitExpr<float>(20.12);
    test_BinOpExpr<float, BinOp::add, TestType::as_string>(lit1, lit2);
  } break;
  case 8: {
    LitExpr<float> *lit1 = new LitExpr<float>(20.23);
    LitExpr<float> *lit2 = new LitExpr<float>(20.12);
    test_BinOpExpr<float, BinOp::add, TestType::eval>(lit1, lit2);
  } break;
  case 9: {
    LitExpr<float> *lit1 = new LitExpr<float>(20.23);
    LitExpr<float> *lit2 = new LitExpr<float>(20.12);
    test_BinOpExpr<float, BinOp::sub, TestType::as_string>(lit1, lit2);
  } break;
  case 10: {
    LitExpr<float> *lit1 = new LitExpr<float>(20.23);
    LitExpr<float> *lit2 = new LitExpr<float>(20.12);
    test_BinOpExpr<float, BinOp::sub, TestType::eval>(lit1, lit2);
  } break;
  case 11: {
    LitExpr<float> *lit1 = new LitExpr<float>(20.23);
    LitExpr<float> *lit2 = new LitExpr<float>(20.12);
    test_BinOpExpr<float, BinOp::mul, TestType::as_string>(lit1, lit2);
  } break;
  case 12: {
    LitExpr<float> *lit1 = new LitExpr<float>(20.23);
    LitExpr<float> *lit2 = new LitExpr<float>(20.12);
    test_BinOpExpr<float, BinOp::mul, TestType::eval>(lit1, lit2);
  } break;
  case 13: {
    LitExpr<float> *lit1 = new LitExpr<float>(20.23);
    LitExpr<float> *lit2 = new LitExpr<float>(20.12);
    test_BinOpExpr<float, BinOp::div, TestType::as_string>(lit1, lit2);
  } break;
  case 14: {
    LitExpr<float> *lit1 = new LitExpr<float>(20.23);
    LitExpr<float> *lit2 = new LitExpr<float>(20.12);
    test_BinOpExpr<float, BinOp::div, TestType::eval>(lit1, lit2);
  } break;
  case 15: {
    LitExpr<float> *lit = new LitExpr<float>(20.12);
    NegExpr<float> *unop = new NegExpr<float>(lit);
    test_UnOpExpr<float, UnOp::pos, TestType::as_string>(unop);
  } break;
  case 16: {
    LitExpr<float> *lit = new LitExpr<float>(20.12);
    NegExpr<float> *unop = new NegExpr<float>(lit);
    test_UnOpExpr<float, UnOp::pos, TestType::eval>(unop);
  } break;
  case 17: {
    LitExpr<float> lit1(20.23);
    LitExpr<float> lit2(20.12);
    AddExpr<float> *lhs =
        new AddExpr<float>(new LitExpr<float>(lit1), new LitExpr<float>(lit2));
    SubExpr<float> *rhs =
        new SubExpr<float>(new LitExpr<float>(lit1), new LitExpr<float>(lit2));
    test_BinOpExpr<float, BinOp::mul, TestType::as_string>(lhs, rhs);
  } break;
  case 18: {
    LitExpr<float> lit1(20.23);
    LitExpr<float> lit2(20.12);
    AddExpr<float> *lhs =
        new AddExpr<float>(new LitExpr<float>(lit1), new LitExpr<float>(lit2));
    SubExpr<float> *rhs =
        new SubExpr<float>(new LitExpr<float>(lit1), new LitExpr<float>(lit2));
    test_BinOpExpr<float, BinOp::mul, TestType::eval>(lhs, rhs);
  } break;
  case 19: {
    LitExpr<float> lit1(20.23);
    LitExpr<float> lit2(20.12);
    AddExpr<float> *lhs =
        new AddExpr<float>(new LitExpr<float>(lit1), new LitExpr<float>(lit2));
    SubExpr<float> *binop =
        new SubExpr<float>(new LitExpr<float>(lit1), new LitExpr<float>(lit2));
    NegExpr<float> *rhs =
        new NegExpr<float>(binop);
    test_BinOpExpr<float, BinOp::mul, TestType::as_string>(lhs, rhs);
  } break;
  case 20: {
    LitExpr<float> lit1(20.23);
    LitExpr<float> lit2(20.12);
    AddExpr<float> *lhs =
        new AddExpr<float>(new LitExpr<float>(lit1), new LitExpr<float>(lit2));
    SubExpr<float> *binop =
        new SubExpr<float>(new LitExpr<float>(lit1), new LitExpr<float>(lit2));
    NegExpr<float> *rhs =
        new NegExpr<float>(binop);
    test_BinOpExpr<float, BinOp::mul, TestType::eval>(lhs, rhs);
  } break;
  default:
    std::cout << "Invalid test case" << std::endl;
    return -1;
  }
}
