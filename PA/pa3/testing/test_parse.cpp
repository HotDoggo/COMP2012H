#include "parse.h"
#include "expression.h"
#include <iostream>
#include <string>
#include <functional>

template <typename T>
std::function<Expr<T>*(const std::string)> get_parser(std::string type) {
  if (type == "literal")
    return parse_literal<T>;
  if (type == "primary")
    return parse_primary<T>;
  if (type == "factor")
    return parse_factor<T>;
  if (type == "term")
    return parse_term<T>;
  return parse<T>;
}

template <typename T> void test_parse(std::string str, std::string type) {
  std::cout << "Parsing \"" << str << "\" as " << type << std::endl;
  Expr<T> *expr = get_parser<T>(type)(str);
  if (expr) {
    std::cout << "String: \"" << expr->as_string() << "\"" << std::endl;
    std::cout << "Value: " << expr->eval() << std::endl;
    delete expr;
  } else {
    std::cout << "Cannot parse as " << type << std::endl;
  }
}

int main() {
  int test_case;
  std::cin >> test_case;
  switch (test_case) {
  case 1:
    test_parse<int>("", "literal");
    test_parse<int>("  2023", "literal");
    test_parse<int>("2023  ", "literal");
    test_parse<int>("2023.  ", "literal");
    test_parse<int>(" 20.12", "literal");
    break;
  case 2:
    test_parse<int>("", "literal");
    test_parse<int>("2023", "literal");
    test_parse<int>("(20+23)", "literal");
    test_parse<int>("-2023", "literal");
    test_parse<int>("20/23", "literal");
    test_parse<int>("20+23", "literal");
    break;
  case 3:
    test_parse<int>("", "primary");
    test_parse<int>("  2023", "primary");
    test_parse<int>("(())", "primary");
    test_parse<int>("(2+0*-(2+3))", "primary");
    test_parse<int>(" (2023 ", "primary");
    test_parse<int>(" (2023", "primary");
    break;
  case 4:
    test_parse<int>("", "primary");
    test_parse<int>("2023", "primary");
    test_parse<int>("(20+23)", "primary");
    test_parse<int>("-2023", "primary");
    test_parse<int>("20/23", "primary");
    test_parse<int>("20+23", "primary");
    break;
  case 5:
    test_parse<int>("", "factor");
    test_parse<int>("  2023", "factor");
    test_parse<int>("-2023", "factor");
    test_parse<int>("+ - + - + -  2023", "factor");
    test_parse<int>("---- + -   - 2023", "factor");
    break;
  case 6:
    test_parse<int>("", "factor");
    test_parse<int>("2023", "factor");
    test_parse<int>("(20+23)", "factor");
    test_parse<int>("-2023", "factor");
    test_parse<int>("20/23", "factor");
    test_parse<int>("20+23", "factor");
    break;
  case 7:
    test_parse<int>("", "term");
    test_parse<int>("123", "term");
    test_parse<int>("  - 2024", "term");
    test_parse<int>("20 * 2*3", "term");
    test_parse<int>(" 20 / 2*3", "term");
    break;
  case 8:
    test_parse<int>("", "term");
    test_parse<int>("2023", "term");
    test_parse<int>("(20+23)", "term");
    test_parse<int>("-2023", "term");
    test_parse<int>("20/23", "term");
    test_parse<int>("20+23", "term");
    break;
  case 9:
    test_parse<int>("", "expression");
    test_parse<int>("  20 + 23", "expression");
    test_parse<int>("20+ 2*3  ", "expression");
    test_parse<int>("2-0-2-3.  ", "expression");
    test_parse<int>("2 - 0  +2  *3", "expression");
    break;
  case 10:
    test_parse<int>("", "expression");
    test_parse<int>("2023", "expression");
    test_parse<int>("(20+23)", "expression");
    test_parse<int>("-2023", "expression");
    test_parse<int>("20/23", "expression");
    test_parse<int>("20+23", "expression");
    break;
  default:
    std::cout << "Invalid test case!" << std::endl;
    return -1;
  }
}
