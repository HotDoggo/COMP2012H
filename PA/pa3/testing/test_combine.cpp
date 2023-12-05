#include <iostream>
#include <vector>
#include <string>
#include "expression.h"
#include "complex.h"
#include "parse.h"
#include "utils.h"
using namespace std;

template<typename T>
void parse_eval(string input) {
	cout << "Parsing \"" << input << "\" ..." << endl;
	Expr<T>* expr_ptr;
	expr_ptr = parse<T>(input);
	if (expr_ptr != nullptr) {
			cout << "It is parsed as:" << endl;
			cout << "    " << expr_ptr->as_string() << endl;
			cout << "It is evaluated as: " << to_str(expr_ptr->eval()) << "." << endl;
			delete expr_ptr;
		} else {
			cout << "Invalid expression" << endl;
		}
}
enum class Mode {
	int_mode,
	float_mode,
	complex_long_mode,
	complex_double_mode,
};

struct TestCase {
	string description;
	Mode mode;
	vector<string> inputs;
};

vector<TestCase> test_cases = {
	//1
	TestCase{
		"Test on int literal parsing 1",
		Mode::int_mode,
		{
			"2012",
			"002012",
			"  12",
			"20  ",
			" 01 ",
		}
	},
	//2
	TestCase{
		"Test on int literal parsing 2",
		Mode::int_mode,
		{
			"comp2012h",
			"20.12",
			"12i",
			"12.1i",
		}
	},
	//3
	TestCase{
		"Test on float literal parsing 1",
		Mode::float_mode,
		{
			"2012",
			"02012",
			"20.12",
			"20.",
			".12",
			"  20.",
			"    20.",
			".12   ",
			"   20.    ",
		}
	},
	//4
	TestCase{
		"Test on float literal parsing 2",
		Mode::float_mode,
		{
			"comp2012h",
			"2012i",
			"20.12i",
			"20+12i",
			"20-12.1i",
		}
	},
	//5
	TestCase{
		"Test on Complex<long> literal parsing 1",
		Mode::complex_long_mode,
		{
			"2012",
			"002012",
			"  12",
			"20  ",
			" 01 ",
		}
	},
	//6
	TestCase{
		"Test on Complex<long> literal parsing 2",
		Mode::complex_long_mode,
		{
			"2012i",
			"002012i",
			"  12i",
			"20i  ",
			" 01i ",
		}
	},
	//7
	TestCase{
		"Test on Complex<long> literal parsing 3",
		Mode::complex_long_mode,
		{
			"comp2012h",
			"20.12",
			".12",
			"12.",
		}
	},
	//8
	TestCase{
		"Test on Complex<long> literal parsing 4",
		Mode::complex_long_mode,
		{
			"comp2012hi",
			"i",
			"20.12i",
			"12.1i",
			".12i",
			"12.i",
			"2012   i",
		}
	},
	//9
	TestCase{
		"Test on Complex<double> literal parsing 1",
		Mode::complex_double_mode,
		{
			"2012",
			"02012",
			"20.12",
			"20.",
			".12",
			"  20.",
			"    20.",
			".12   ",
			"   20.    ",
		}
	},
	//10
	TestCase{
		"Test on Complex<double> literal parsing 2",
		Mode::complex_double_mode,
		{
			"2012i",
			"02012i",
			"20.12i",
			"20.i",
			".12i",
			"  20.i",
			"    20.i",
			".12i   ",
			"   20.i    ",
		}
	},
	//11
	TestCase{
		"Test on Complex<double> literal parsing 3",
		Mode::complex_double_mode,
		{
			"comp2012h",
			"  i",
			"20 + 12i",
			"20 - 12i",
			"20.12 + 20.12i",
			"20. + .12i",
			"20.12 - 20.12i",
			"20. - .12i",
			"+2012",
			"+2012i",
			"-2012i",
		}
	},
	//12
	TestCase{
		"Test on expression parsing & evaluation 1",
		Mode::float_mode,
		{
			"+21.02",
			"-21.02",
			"20.12 + 21.02",
			"20.12 - 21.02",
			"20.12 * 21.02",
			"20.12 / 21.02",
		}
	},
	//13
	TestCase{
		"Test on expression parsing & evaluation 2",
		Mode::float_mode,
		{
			"   20.12+21.02",
			"20.12-21.02   ",
			" 20.12*21.02  ",
			"20.12/21.02",
			"  +   2021.",
			"-.2012",
		}
	},
	//14
	TestCase{
		"Test on expression parsing & evaluation 3",
		Mode::float_mode,
		{
			"20 ++--++--++ 12",
			"1 + 2 + 3 + 4 + 5",
			"1 - 2 - 3 - 4 - 5",
			"1 * 2 * 3 * 4 * 5",
			"1 / 2 / 3 / 4 / 5",
		}
	},
	//15
	TestCase{
		"Test on expression parsing & evaluation 4",
		Mode::float_mode,
		{
			"1 + 2 - 3 * 4 / 5",
			"1 - 2 * 3 / 4 + 5",
			"1 * 2 / 3 + 4 - 5",
			"1 / 2 + 3 - 4 * 5",
			"2+0*-1+2",
			"2 + 0 * - 1 + 2",
			"2 + 0 * + 1 + 2",
		}
	},
	//16
	TestCase{
		"Test on expression parsing & evaluation 5",
		Mode::float_mode,
		{
			"1 + 2 - 3 * 4 / 5",
			"1 - 2 * 3 / 4 + 5",
			"1 * 2 / 3 + 4 - 5",
			"1 / 2 + 3 - 4 * 5",
			"2+0*-1+2",
			"2 + 0 * - 1 + 2",
			"2 + 0 * + 1 + 2",
		}
	},
	//17
	TestCase{
		"Test on expression parsing & evaluation 6",
		Mode::float_mode,
		{
			"(1 + 2) - 3 * 4 / 5",
			"1 - (2 * 3) / 4 + 5",
			"1 * 2 / (3 + 4) - 5",
			"1 / 2 + 3 - (4 * 5)",
			"(2 + 0) * - 1 + 2",
			"2 + (0) * - 1 + 2",
			"2 + (0 * - 1) + 2",
			"2 + 0 * (+ 1) + 2",
			"2 + 0 * (+ 1 + 2)",
		}
	},
	//18
	TestCase{
		"Test on expression parsing & evaluation 7",
		Mode::float_mode,
		{
			"(1 + 2) - 3 * 4 / 5",
			"1 - (2 * 3) / 4 + 5",
			"1 * 2 / (3 + 4) - 5",
			"1 / 2 + 3 - (4 * 5)",
			"(2 + 0) * - 1 + 2",
			"2 + (0) * - 1 + 2",
			"2 + (0 * - 1) + 2",
			"2 + 0 * (+ 1) + 2",
			"2 + 0 * (+ 1 + 2)",
		}
	},
	//19
	TestCase{
		"Test on expression parsing & evaluation 8",
		Mode::float_mode,
		{
			"(1 + 2)* +- (2*(2+3*(3+5)))",
			"(1 + 2)* +- (2*(2+3*(3+5))",
			"((((2))+((5)))))",
			")(+(5)()",
			"1*-2*--3*---4*----5*-----6*------7*-------8*--------9",
		}
	},
	//20
	TestCase{
		"Test on expression parsing & evaluation 8",
		Mode::complex_long_mode,
		{
			"+-+-+--++--+++ 1i",
			"(1 + 1i) * (1 - 1i)",
			"(1 + 1i) / (1 - 1i)",
			"2 * 0i + -(1i + 2)",
			"((2 + 0i) * -1i /2i)",
			"1i * 1i / 1i * 1i / 1i",
			"1i + 1i + 1i + 1i + 1i",
			"1i * 1i * 1i * 1i / 1i",
		}
	},
};

int test_case(int case_id) {
	if (case_id >= 1 && case_id <= test_cases.size()) {
		TestCase test_case = test_cases[case_id-1];
		cout << "=========================================" << endl;
		cout << test_case.description << endl;
		switch (test_case.mode) {
			case Mode::int_mode:
				for (int i = 0; i < test_case.inputs.size(); i++) {
					parse_eval<int>(test_case.inputs[i]);
					cout << endl;
				}
				break;
			case Mode::float_mode:
				for (int i = 0; i < test_case.inputs.size(); i++) {
					parse_eval<float>(test_case.inputs[i]);
					cout << endl;
				}
				break;
			case Mode::complex_long_mode:
				for (int i = 0; i < test_case.inputs.size(); i++) {
					parse_eval<Complex<long>>(test_case.inputs[i]);
					cout << endl;
				}
				break;
			case Mode::complex_double_mode:
				for (int i = 0; i < test_case.inputs.size(); i++) {
					parse_eval<Complex<double>>(test_case.inputs[i]);
					cout << endl;
				}
				break;
		}
		cout << "=========================================" << endl;
		return 0;
	}
	else {
		cout << "It is a invalid test case" << endl;
		return 1;
	}
}

int main(int argc, char* argv[]) {
	int case_id = 0;
	cin >> case_id;

	return test_case(case_id);
}
