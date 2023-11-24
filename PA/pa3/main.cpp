#include <iostream>
#include <string>
#include "expression.h"
#include "parse.h"
#include "complex.h"
#include "utils.h"
using namespace std;

template <typename T>
void read_eval_print_loop()
{
	string input;
	Expr<T> *expr_ptr;
	while (true)
	{
		// prompt
		cout << ">>> ";
		getline(cin, input);

		// check if exit
		input = trim(input);
		if (input == "exit")
		{
			break;
		}

		expr_ptr = parse<T>(input);
		if (expr_ptr != nullptr)
		{
			cout << "Your input is parsed as:" << endl;
			cout << "    " << expr_ptr->as_string() << endl;
			cout << "It is evaluated as: " << to_str(expr_ptr->eval()) << "." << endl;
			delete expr_ptr;
		}
		else
		{
			cout << "I don't understand your input." << endl;
		}
	}
}

void usage_info()
{
	cout << "This is a basic calculator written in cpp" << endl;
	cout << "# Launch with PA3.exe [MODE]. MODE can be int, float or complex.    #" << endl;
	cout << "# The default mode is float. Type expression to calculate.          #" << endl;
	cout << "# Type exit to quit.                                                #" << endl;
	cout << endl;
}

int main(int argc, char *argv[])
{
	usage_info();
	string mode = "float";
	if (argc == 2)
	{
		mode = argv[1];
	}
	if (mode == "float")
	{
		cout << "It is running in the float mode." << endl;
		read_eval_print_loop<float>();
	}
	else if (mode == "int")
	{
		cout << "It is running in the int mode." << endl;
		read_eval_print_loop<int>();
	}
	else if (mode == "complex")
	{
		cout << "It is running in the complex mode." << endl;
		read_eval_print_loop<Complex<double>>();
	}
	else
	{
		cout << "Invalid mode!" << endl;
	}
}
