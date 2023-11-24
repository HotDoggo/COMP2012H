/**
 * @file expression.h
 *
 * @brief Expr and derived class template declarations and definitions.
 *
 * This file declares and defines:
 *   1. an abstract class template Expr to represent a general expression for different types.
 *   2. a class template LitExpr to represent a literal expression for different types.
 *   3. a class template UnOpExpr to represent an unary operation expression for different types.
 *   4. a class template BinOpExpr to represent a binary operation expression for different types.
 */

#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int default_precision = 5;

// Convert val to string with required precision.
template <typename T>
string to_str(const T &val, int precision = default_precision);

// Definition of the class template Expr.
template <typename T>
class Expr
{
	// Abstract class: a general expression.

public:
	// Virtual destructor
	virtual ~Expr() = default;

	// Evaluate this expression and return its value.
	virtual T eval() const = 0;

	// Convert this expression as a string.
	virtual string as_string(int precision = default_precision) const = 0;
};

// Definition of the class template LitExpr.
template <typename T>
class LitExpr : public Expr<T>
{
	// Literal expression of type T.

private:
	// Its value.
	T value;

public:
	// Constructor, make a literal expression of value.
	LitExpr(T value);

	// Destructor
	virtual ~LitExpr() = default;

	// Return its value.
	virtual T eval() const;

	// Return a string represent its value.
	virtual string as_string(int precision = default_precision) const;
};

// Supported unary operations.
enum class UnOp
{
	pos, // +(x).
	neg, // -(x).
};

// Definition of the class template UnOpExpr.
template <typename T, UnOp op>
class UnOpExpr : public Expr<T>
{
	// Expression of applying an unary operation on another.

private:
	// The expression the operation applies to.
	Expr<T> *operand;

public:
	// Constructor, make a unary operation expression of op(*operand).
	UnOpExpr(Expr<T> *operand);

	// Destructor.
	virtual ~UnOpExpr();

	// Evaluate its value.
	virtual T eval() const;

	// Return a string represent this expression.
	virtual string as_string(int precision = default_precision) const;
};

// Supported binary operations.
enum class BinOp
{
	add, //(x) + (y).
	sub, //(x) - (y).
	mul, //(x) * (y).
	div, //(x) / (y).
};

// Definition of the class template BinOpExpr.
template <typename T, BinOp op>
class BinOpExpr : public Expr<T>
{
	// Expression of applying an unary operation on another.

private:
	// The left hand side operand of the operation.
	Expr<T> *lhs;
	// The right hand side operand of the operation.
	Expr<T> *rhs;

public:
	// Constructor, make a binary operation expression of (*lhs) op (*rhs).
	BinOpExpr(Expr<T> *lhs, Expr<T> *rhs);

	// Destructor.
	virtual ~BinOpExpr();

	// Evaluate its value.
	virtual T eval() const;

	// Return a string represent this expression.
	virtual string as_string(int precision = default_precision) const;
};

// Aliasing
template <typename T>
using PosExpr = UnOpExpr<T, UnOp::pos>;

template <typename T>
using NegExpr = UnOpExpr<T, UnOp::neg>;

template <typename T>
using AddExpr = BinOpExpr<T, BinOp::add>;

template <typename T>
using SubExpr = BinOpExpr<T, BinOp::sub>;

template <typename T>
using MulExpr = BinOpExpr<T, BinOp::mul>;

template <typename T>
using DivExpr = BinOpExpr<T, BinOp::div>;

#include "expression.tpp"
#endif // __EXPRESSION_H__
