/**
 * @file complex.tpp
 *
 * @brief Member functions, and overloading functions and operators
 * for the Complex class template in complex.h.
 *
 * This file defines member functions of the Complex class template.
 * To support parsing and evaluating a expression of type Complex<T>,
 * it also defines several overloading functions and operators.
 *
 * It is assumed that there are these overloading functions and operators for the type T.
 */

/**
 * Please define your Complex member functions and overloading functions and operators
 * you need to support parsing and evaluating Expr<Complex<T>>.
 */
//================ TODO =======================================================
template <typename T>
bool str_to_val(const string &str, Complex<T> &val)
{
    if (str.back() == 'i')
    {
        string imaginary_string = str.substr(0, str.size() - 1);
        T imaginary_num;
        if (!str_to_val(imaginary_string, imaginary_num))
            return false;
        val = Complex<T>(0, imaginary_num);
        return true;
    }
    else
    {
        T real_num;
        if (!str_to_val(str, real_num))
            return false;
        val = Complex<T>(real_num, 0);
        return true;
    }

    return false;
}

// template <>
// bool str_to_val(const string &str, Complex<double> &val);

template <typename T>
string to_str(const Complex<T> &val, int precision)
{
    ostringstream out;
    out.precision(precision);
    if (val.get_real() != 0)
    {
        out << val.get_real();
        out << (val.get_imaginary() >= 0 ? " + " : " - ");
        out << abs(val.get_imaginary()) << "i";
    }
    else
    {
        out << val.get_imaginary() << "i";
    }
    return out.str();
}

template <typename T>
Complex<T>::Complex(T real, T imaginary) : real(real), imaginary(imaginary){};

template <typename T>
T Complex<T>::get_real() const { return this->real; }

template <typename T>
T Complex<T>::get_imaginary() const { return this->imaginary; }

template <typename T>
Complex<T> Complex<T>::operator+(const Complex<T> &val) const { return Complex<T>(real + val.real, imaginary + val.imaginary); }

template <typename T>
Complex<T> Complex<T>::operator-(const Complex<T> &val) const { return Complex<T>(real - val.real, imaginary - val.imaginary); }

template <typename T>
Complex<T> Complex<T>::operator-() const { return Complex<T>(-real, -imaginary); }

template <typename T>
Complex<T> Complex<T>::operator*(const Complex<T> &val) const
{
    T new_real = real * val.real - imaginary * val.imaginary;
    T new_imaginary = real * val.imaginary + imaginary * val.real;
    return Complex<T>(new_real, new_imaginary);
}

template <typename T>
Complex<T> Complex<T>::operator/(const Complex<T> &val) const
{
    T divisor = val.real * val.real + val.imaginary * val.imaginary;
    T new_real = (real * val.real + imaginary * val.imaginary) / divisor;
    T new_imaginary = (imaginary * val.real - real * val.imaginary) / divisor;
    return Complex<T>(new_real, new_imaginary);
}

// template <typename T>
// ostream &operator<<(ostream &os, const Complex<T> &complex)
// {
//     os << complex.get_real();
//     os << (complex.get_imaginary() >= 0 ? " + " : " - ");
//     os << abs(complex.get_imaginary()) << "i";

//     return os;
// }
//-----------------------------------------------------------------------------
