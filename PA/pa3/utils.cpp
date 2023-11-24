/**
 * @file utils.cpp
 *
 * @brief Helper functions definitions.
 *
 * This file defines some helper functions for parsing expressions.
 */

#include "utils.h"

/**
 * Check if str only contains digits.
 *
 * If str is empty return false.
 * more like only_digits + check if there multiple '.'s + check if its literally just '.'
 */
bool only_digits(const string &str)
{
	bool out = false;

	//================ TODO ======================================================
	int temp = str.find_first_of("."), count = 0;
	while (temp != string::npos)
	{
		count++;
		temp = str.find_first_of(".", temp + 1);
	}
	out = str.find_first_not_of("0123456789.") == string::npos && !str.empty() && count <= 1;
	if (count == 1 && str.size() == 1)
		out = false;
	//----------------------------------------------------------------------------
	return out;
}

/**
 * Define the template specialization for
 * converting str to a int type value.
 *
 * Check if str is a string of int type.
 * If so, write the value to val using stoi(), output true.
 * Otherwise, return false.
 *
 * A string of int type must be non-empty and made of only digits.
 */
//================ TODO ======================================================
template <>
bool str_to_val(const string &str, int &val)
{
	if (only_digits(str) && (str.find('.') == string::npos))
	{
		size_t pos;
		int temp = stoi(str, &pos);
		if (str.size() == pos)
		{
			val = temp;
			return true;
		}
	}
	return false;
}
//----------------------------------------------------------------------------

/**
 * Define the template specialization for
 * converting str to a long type value.
 *
 * Check if str is a string of long type.
 * If so, write the value to val using stol(), output true.
 * Otherwise, return false.
 *
 * A string of long must be a string of type int.
 */
//================ TODO ======================================================
template <>
bool str_to_val(const string &str, long &val)
{
	if (only_digits(str) && (str.find('.') == string::npos))
	{
		size_t pos;
		long temp = stol(str, &pos);
		if (str.size() == pos)
		{
			val = temp;
			return true;
		}
	}
	return false;
}
//----------------------------------------------------------------------------

/**
 * Define the template specialization for
 * converting str to a float type value.
 *
 * Check if str is a string of float type.
 * If so, write the value to val using stof(), output true.
 * Otherwise, return false.
 *
 * Rules for a string of float:
 *   1. A string of type int is a string of type float.
 *   2. "." + a string of type int is a string of type float.
 *   3. A string of type int + "." is a string of type float.
 *   4. Two strings of type int connected by a "." is a string of type float.
 *   5. Otherwise, it is not.
 */
//================ TODO ======================================================
template <>
bool str_to_val(const string &str, float &val)
{
	if (only_digits(str))
	{
		size_t pos;
		float temp = stof(str, &pos);
		if (str.size() == pos)
		{
			val = temp;
			return true;
		}
	}
	return false;
}
//----------------------------------------------------------------------------

/**
 * Define the template specialization for
 * converting str to a double type value.
 *
 * Check if str is a string of double type.
 * If so, write the value to val using stod(), output true.
 * Otherwise, return false.
 *
 * A string of double type must be a string of float type.
 */
//================ TODO ======================================================
template <>
bool str_to_val(const string &str, double &val)
{
	if (only_digits(str))
	{
		size_t pos;
		double temp = stod(str, &pos);
		if (str.size() == pos)
		{
			val = temp;
			return true;
		}
	}
	return false;
}
//----------------------------------------------------------------------------

/**
 * Return a copy of str with all WHITESPACEs from two ends removed.
 *
 */
string trim(const string &str)
{
	string trim = str;
	//================ TODO ======================================================
	int start = str.find_first_not_of(WHITESPACE);
	int end = str.find_last_not_of(WHITESPACE);

	trim = start == string::npos ? "" : trim.substr(start, end - start + 1);
	//----------------------------------------------------------------------------
	return trim;
}