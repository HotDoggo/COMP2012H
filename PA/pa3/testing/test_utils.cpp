#include "utils.h"
#include <string>

void test_only_digits(std::string str) {
  std::cout << "==== Only-Digits ====" << std::endl;
  std::cout << "Input: \"" << str << "\"" << std::endl;
  std::cout << "OnlyDigits: " << (only_digits(str)? "True":"False") << std::endl;
  std::cout << std::endl;
}

template <typename T> void test_str_to_val(std::string str) {
  std::cout << "==== Str-To-Val ====" << std::endl;
  std::cout << "Input: \"" << str << "\"" << std::endl;
  T val;
  if (str_to_val(str, val)) {
    std::cout << "Value: " << val << std::endl;
  } else {
    std::cout << "Cannot convert!" << std::endl;
  }
  std::cout << std::endl;
}

void test_trim(std::string str) {
  std::cout << "==== Trim ====" << std::endl;
  std::cout << "Input: \"" << str << "\"" << std::endl;
  std::cout << "Trimmed: \"" << trim(str) << "\"" << std::endl;
  std::cout << std::endl;
}

int main() {
  int test_case;
  std::cin >> test_case;
  switch (test_case) {
  case 1:
    test_only_digits("");
    test_only_digits("abc3");
    test_only_digits("2bcd");
    test_only_digits("2bc3");
    test_only_digits("a02d");
    test_only_digits("2023");
    test_only_digits("  2023");
    test_only_digits("2023");
    test_only_digits("  2023  ");
    test_only_digits("20.23");
    break;
  case 2:
    test_trim("  abcd    ");
    test_trim(" abcd \n ");
    test_trim("  ab cd    ");
    test_trim(" ab cd \n ");
    test_trim("  a b c d    ");
    test_trim(" a b c d \n ");
    test_trim("");
    test_trim("abcd");
    test_trim("  abcd");
    test_trim("abcd  ");
    test_trim("a  b c   d");
    break;
  case 3:
    std::cout << "======== TYPE: INT ========" << std::endl;
    test_str_to_val<int>("");
    test_str_to_val<int>("2023");
    test_str_to_val<int>(".");
    test_str_to_val<int>("20.23");
    test_str_to_val<int>(".2023");
    test_str_to_val<int>("2023.");
    break;
  case 4:
    std::cout << "======== TYPE: INT ========" << std::endl;
    test_str_to_val<int>("  ");
    test_str_to_val<int>("2023  ");
    test_str_to_val<int>("  .");
    test_str_to_val<int>("20.23  ");
    test_str_to_val<int>("  .2023");
    test_str_to_val<int>("2023.  ");
    break;
  case 5:
    std::cout << "======== TYPE: LONG ========" << std::endl;
    test_str_to_val<long>("");
    test_str_to_val<long>("2023");
    test_str_to_val<long>(".");
    test_str_to_val<long>("20.23");
    test_str_to_val<long>(".2023");
    test_str_to_val<long>("2023.");
    break;
  case 6:
    std::cout << "======== TYPE: LONG ========" << std::endl;
    test_str_to_val<long>("  ");
    test_str_to_val<long>("2023  ");
    test_str_to_val<long>("  .");
    test_str_to_val<long>("20.23  ");
    test_str_to_val<long>("  .2023");
    test_str_to_val<long>("2023.  ");
    break;
  case 7:
    std::cout << "======== TYPE: FLOAT ========" << std::endl;
    test_str_to_val<float>("");
    test_str_to_val<float>("2023");
    test_str_to_val<float>(".");
    test_str_to_val<float>("20.23");
    test_str_to_val<float>(".2023");
    test_str_to_val<float>("2023.");
    test_str_to_val<float>("20.23e2012");
    break;
  case 8:
    std::cout << "======== TYPE: FLOAT ========" << std::endl;
    test_str_to_val<float>("  ");
    test_str_to_val<float>("2023  ");
    test_str_to_val<float>("  .");
    test_str_to_val<float>("20.23  ");
    test_str_to_val<float>("  .2023");
    test_str_to_val<float>("2023.  ");
    test_str_to_val<float>("2023  .");
    test_str_to_val<float>(". 2023");
    test_str_to_val<float>("20. 23");
    test_str_to_val<float>("20.2.3");
    test_str_to_val<float>("  20.23e2012");
    break;
  case 9:
    std::cout << "======== TYPE: DOUBLE ========" << std::endl;
    test_str_to_val<double>("");
    test_str_to_val<double>("2023");
    test_str_to_val<double>(".");
    test_str_to_val<double>("20.23");
    test_str_to_val<double>(".2023");
    test_str_to_val<double>("2023.");
    test_str_to_val<double>("20.23e2012");
    break;
  case 10:
    std::cout << "======== TYPE: DOUBLE ========" << std::endl;
    test_str_to_val<double>("  ");
    test_str_to_val<double>("2023  ");
    test_str_to_val<double>("  .");
    test_str_to_val<double>("20.23  ");
    test_str_to_val<double>("  .2023");
    test_str_to_val<double>("2023.  ");
    test_str_to_val<double>("2023  .");
    test_str_to_val<double>(". 2023");
    test_str_to_val<double>("20. 23");
    test_str_to_val<double>("20.2.3");
    test_str_to_val<double>("  20.23e2012");
    break;
  default:
    std::cout << "Invalid test case!" << std::endl;
    return -1;
  }
}
