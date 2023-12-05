#include "complex.h"
#include "expression.h"
#include <iostream>
#include <string>
#include "parse.h"

template <typename T>
void test_IO(std::string str)
{
  std::cout << "==== Test IO ====" << std::endl;
  std::cout << "Input: \"" << str << "\"" << std::endl;
  Complex<T> cplx;
  if (str_to_val(str, cplx))
  {
    std::cout << "Value: " << to_str(cplx) << std::endl;
  }
  else
  {
    std::cout << "Cannot convert!" << std::endl;
  }
  std::cout << std::endl;
}

template <typename T>
void test_unary(std::string operand_str, std::string op_str)
{
  std::cout << "==== Test unary: " << op_str << " ====" << std::endl;
  std::cout << "Input: \"" << operand_str << "\"" << std::endl;
  Complex<T> cplx;
  if (str_to_val(operand_str, cplx))
  {
    if (op_str == "+")
    {
      PosExpr<Complex<T>> *pos_expr = new PosExpr<Complex<T>>(new LitExpr<Complex<T>>(cplx));
      std::cout << "+x: " << to_str(pos_expr->eval()) << std::endl;
      delete pos_expr;
    }
    if (op_str == "-")
    {
      NegExpr<Complex<T>> *neg_expr = new NegExpr<Complex<T>>(new LitExpr<Complex<T>>(cplx));
      std::cout << "-x: " << to_str(neg_expr->eval()) << std::endl;
      delete neg_expr;
    }
  }
  else
  {
    std::cout << "Cannot convert!" << std::endl;
  }
  std::cout << std::endl;
}

template <typename T>
void test_binary(std::string lhs_str, std::string rhs_str, std::string op_str)
{
  std::cout << "==== Test binary: " << op_str << " ====" << std::endl;
  std::cout << "Input: \"" << lhs_str << "\" & \"" << rhs_str << "\"" << std::endl;
  Complex<T> lhs, rhs;
  if (str_to_val(lhs_str, lhs) && str_to_val(rhs_str, rhs))
  {
    if (op_str == "+")
    {
      std::cout << "x+y: " << to_str(lhs + rhs) << std::endl;
    }
    if (op_str == "-")
    {
      std::cout << "x-y: " << to_str(lhs - rhs) << std::endl;
    }
    if (op_str == "*")
    {
      std::cout << "x*y: " << to_str(lhs * rhs) << std::endl;
    }
    if (op_str == "/")
    {
      std::cout << "x/y: " << to_str(lhs / rhs) << std::endl;
    }
  }
  else
  {
    std::cout << "Cannot convert!" << std::endl;
  }
  std::cout << std::endl;
}

template <typename T>
void test_expr(std::string str)
{
  Expr<Complex<T>> *expr;
  std::cout << "==== Test Expr ====" << std::endl;
  std::cout << "Input: \"" << str << "\"" << std::endl;
  expr = parse<Complex<T>>(str);
  if (expr)
  {
    std::cout << "String: \"" << expr->as_string() << "\"" << std::endl;
    std::cout << "Value: " << expr->eval() << std::endl;
    delete expr;
  }
  else
  {
    std::cout << "Cannot parse!" << std::endl;
  }
}

int main()
{
  int test_case;
  std::cin >> test_case;
  switch (test_case)
  {
  case 1:
    test_IO<int>("2023");
    test_IO<int>("2023i");
    test_IO<int>("20.23");
    test_IO<int>("20.23i");
    break;
  case 2:
    test_IO<int>("  2023");
    test_IO<int>("2023 i");
    test_IO<int>("2023i  ");
    test_IO<int>("2023  i  ");
    break;
  case 3:
    test_IO<int>("20 + 23i");
    test_IO<int>("20-23i");
    test_IO<int>("-23i");
    test_IO<int>("-20");
    break;
  case 4:
    test_unary<int>("2023", "+");
    test_unary<int>("2023i", "+");
    test_unary<int>("2023", "-");
    test_unary<int>("2023i", "-");
    break;
  case 5:
    test_binary<int>("20", "23", "+");
    test_binary<int>("20i", "23i", "+");
    test_binary<int>("20", "23i", "+");
    test_binary<int>("20i", "23", "+");
    break;
  case 6:
    test_binary<int>("20", "23", "-");
    test_binary<int>("20i", "23i", "-");
    test_binary<int>("20", "23i", "-");
    test_binary<int>("20i", "23", "-");
    break;
  case 7:
    test_binary<int>("20", "23", "*");
    test_binary<int>("20i", "23i", "*");
    test_binary<int>("20", "23i", "*");
    test_binary<int>("20i", "23", "*");
    break;
  case 8:
    test_binary<int>("20", "23", "/");
    test_binary<int>("20i", "23i", "/");
    test_binary<int>("20", "23i", "/");
    test_binary<int>("20i", "23", "/");
    break;
  case 9:
    test_expr<int>("20+23i");
    test_expr<int>("20-23i");
    test_expr<int>("+23i");
    test_expr<int>("-23i");
    break;
  case 10:
    test_expr<int>("20*23i");
    test_expr<int>("20/23i");
    test_expr<int>("(20 + 23i)*(20 - 23i)");
    test_expr<int>("23i + 20 * 20/23i");
    break;
  default:
    std::cout << "Invalid test case!" << std::endl;
    return -1;
  }
}
