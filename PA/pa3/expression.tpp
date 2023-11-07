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
string to_str(const T& val, int precision) {
    ostringstream out;
    out.precision(precision);
    out << val;
    return out.str();
}

//Definitions of template member functions.
//================ TODO ======================================================

//Your Code Here


//----------------------------------------------------------------------------
