/**
 * @file utils.h
 *
 * @brief Helper functions declarations.
 *
 * This file declares some helper functions for parsing expressions.
 */

#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <iostream>
using namespace std;

// Check if str only contains digits.
bool only_digits(const string &str);

// Change val into actual value represented by str.
// Return true if success.
template <typename T>
bool str_to_val(const string &str, T &val);

// An array of characters considered "whitespace"
const string WHITESPACE = " \n\r\t\f\v";

// Return a trimmed version of str, whose whitespaces on
// two sides of str removed.
string trim(const string &str);

#endif // __UTILS_H__
