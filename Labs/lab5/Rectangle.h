#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length, width;

public:
    // Default constructor
    // Set length and width to 0
    Rectangle();

    // Constructor with parameters provided
    Rectangle(int len, int wid);

    // Set length to provided parameter
    // If input is negative, output "ERROR: Negative length is not allowed" and exit
    // (refer to MyStack.tpp for example)
    void setLength(int l);

    // Return the length of the rectangle
    int getLength() const;

    // Set width to provided parameter
    // If input is negative, output "ERROR: Negative width is not allowed" and exit
    void setWidth(int w);

    // Return the width of the rectangle
    int getWidth() const;

    // Set both length and width of the rectangle
    // If either input is negative, output "ERROR: Negative dimension is not allowed" and exit
    void setDimensions(int len, int wid);

    // Return the area of the triangle (length x width)
    int getArea() const;

    // The overloaded << operator for I/O printing
    // The format should be:
    // "Rectangle: Length = [], Width = [], Area = []" (no endl)
    friend ostream &operator<<(ostream &output, const Rectangle &r);
};

#endif // RECTANGLE_H
