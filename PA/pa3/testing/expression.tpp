/**
 * @file expression.tpp
 *
 * @brief Definitions of member functions of classes in expression.h.
 *
 * This file defines the member functions of the following class template:
 *   1. LitExpr.
 *   2. UnOpExpr.
 *   3. BinOpExpr.
 */

/**
 * Convert val to string with required precision.
 */
template <typename T>
string to_str(const T &val, int precision)
{
    ostringstream out;
    out.precision(precision);
    out << val;
    return out.str();
}

// Definitions of template member functions.
//================ TODO ======================================================
// LitExpr
template <typename T>
LitExpr<T>::LitExpr(T value) : value(value) {}

template <typename T>
T LitExpr<T>::eval() const { return value; }

template <typename T>
string LitExpr<T>::as_string(int precision) const { return to_str(value, precision); }

// UnOpExpr
template <typename T, UnOp op>
UnOpExpr<T, op>::UnOpExpr(Expr<T> *operand) : operand(operand) {}

template <typename T, UnOp op>
UnOpExpr<T, op>::~UnOpExpr() { delete operand; }

template <typename T, UnOp op>
T UnOpExpr<T, op>::eval() const { return op == UnOp::pos ? operand->eval() : -operand->eval(); }

template <typename T, UnOp op>
string UnOpExpr<T, op>::as_string(int precision) const { return op == UnOp::pos ? "+(" + to_str(operand->as_string(), precision) + ")" : "-(" + to_str(operand->as_string(), precision) + ")"; }

// BinOpExpr
template <typename T, BinOp op>
BinOpExpr<T, op>::BinOpExpr(Expr<T> *lhs, Expr<T> *rhs) : lhs(lhs), rhs(rhs) {}

template <typename T, BinOp op>
BinOpExpr<T, op>::~BinOpExpr()
{
    delete lhs;
    delete rhs;
}

template <typename T, BinOp op>
T BinOpExpr<T, op>::eval() const
{
    switch (op)
    {
    case BinOp::add:
        return lhs->eval() + rhs->eval();
        break;
    case BinOp::sub:
        return lhs->eval() - rhs->eval();
        break;
    case BinOp::mul:
        return lhs->eval() * rhs->eval();
        break;
    case BinOp::div:
        return lhs->eval() / rhs->eval();
        break;
    default:
        break;
    }
}

template <typename T, BinOp op>
string BinOpExpr<T, op>::as_string(int precision) const
{

    switch (op)
    {
    case BinOp::add:
        return "(" + lhs->as_string(precision) + ") + (" + rhs->as_string(precision) + ")";
        break;
    case BinOp::sub:
        return "(" + lhs->as_string(precision) + ") - (" + rhs->as_string(precision) + ")";
        break;
    case BinOp::mul:
        return "(" + lhs->as_string(precision) + ") * (" + rhs->as_string(precision) + ")";
        break;
    case BinOp::div:
        return "(" + lhs->as_string(precision) + ") / (" + rhs->as_string(precision) + ")";
        break;
    default:
        break;
    }
}
//----------------------------------------------------------------------------
