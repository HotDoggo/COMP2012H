/**
 * @file complex.h
 *
 * @brief class template for complex numbers.
 *
 * This file declares and defines the Complex class template.
 * It also declares some overloading functions and operators,
 * to support parsing and evaluating expression of type Complex<T> for
 * any type T with these overloading functions and operators.
 *
 */

#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <ostream>
#include <string>
#include "utils.h"
using namespace std;

template <typename T>
class Complex;

/**
 * Please define your Complex and declare overloading functions and operators
 * you need to support parsing and evaluating Expr<Complex<T>>.
 */
//================ TODO =======================================================
template <typename T>
bool str_to_val(const string &str, Complex<T> &val);

template <typename T>
string to_str(const Complex<T> &val, int precision = 5);

template <typename T>
class Complex
{
private:
    T real;
    T imaginary;

public:
    Complex(T real = T(), T imaginary = T());

    T get_real() const;
    T get_imaginary() const;

    Complex<T> operator+(const Complex<T> &val) const;
    Complex<T> operator-(const Complex<T> &val) const;
    Complex<T> operator-() const;
    Complex<T> operator*(const Complex<T> &val) const;
    Complex<T> operator/(const Complex<T> &val) const;
    // friend ostream &operator<<(ostream &os, const Complex<T> &complex);

    string as_string() const;
};
//-----------------------------------------------------------------------------
#include "complex.tpp"
#endif //__COMPLEX_H__
