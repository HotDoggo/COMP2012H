#include "Rectangle.h"
using namespace std;

// TODO: Implement the member functions of Rectangle class,
// as well as the friend overloaded operator.
// Refer to the descriptions in Rectangle.h for details
Rectangle::Rectangle() : Rectangle(0, 0) {}

Rectangle::Rectangle(int len, int wid) : length(len), width(wid) {}

void Rectangle::setLength(int l)
{
    if (l < 0)
    {
        cout << "ERROR: Negative length is not allowed" << endl;
        exit(0);
    }
    length = l;
}

int Rectangle::getLength() const { return length; }

void Rectangle::setWidth(int w)
{
    if (w < 0)
    {
        cout << "ERROR: Negative width is not allowed" << endl;
        exit(0);
    }
    width = w;
}

int Rectangle::getWidth() const { return width; }

void Rectangle::setDimensions(int len, int wid)
{
    if (len < 0 || wid < 0)
    {
        cout << "ERROR: Negative dimension is not allowed" << endl;
        exit(0);
    }
    length = len;
    width = wid;
}

int Rectangle::getArea() const { return (length * width); }

ostream &operator<<(ostream &output, const Rectangle &r)
{
    output << "Rectangle: Length = " << r.length << ", Width = " << r.width << ", Area = " << r.getArea();
    return output;
}