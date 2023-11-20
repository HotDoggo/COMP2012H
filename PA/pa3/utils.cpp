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
 */
bool only_digits(const string &str)
{
	bool out = false;

	//================ TODO ======================================================
	out = str.find_first_not_of("0123456789") == string::npos;
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

// Your Code Here

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

// Your Code Here

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

// Your Code Here

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

// Your Code Here

//----------------------------------------------------------------------------

/**
 * Return a copy of str with all WHITESPACEs from two ends removed.
 *
 */
string trim(const string &str)
{
	string trim = str;
	//================ TODO ======================================================

	// Your Code Here

	//----------------------------------------------------------------------------
	return trim;
}
