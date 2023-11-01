#include <iostream>
#include <string>
#include "MyStack.h"
#include "MyQueue.h"
#include "Rectangle.h"

using namespace std;

int main() {
    // Using Stack with Integers
    MyStack<int> intStack(5);
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.printItems();
    cout << "Is intStack full? " << intStack.isFull() << endl;
    cout << "Popped from intStack: " << intStack.pop() << endl;
    intStack.printItems();
    intStack.clearItems();
    cout << "Is intStack empty? " << intStack.isEmpty() << endl;
    cout << "---------------------------------------------" << endl;

    // Using Stack with Strings
    MyStack<string> stringStack(5);
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.printItems();
    cout << "Popped from stringStack: " << stringStack.pop() << endl;
    stringStack.printItems();
    cout << "---------------------------------------------" << endl;

    // Using Stack with Rectangles
    MyStack<Rectangle> rectangleStack(5);
    rectangleStack.push(Rectangle(2, 3));
    rectangleStack.push(Rectangle(4, 5));
    rectangleStack.printItems();
    Rectangle r1 = rectangleStack.pop();
    cout << "Popped rectangle has area: " << r1.getArea() << endl;
    rectangleStack.printItems();
    cout << "---------------------------------------------" << endl;

    // Using Queue with Integers
    MyQueue<int> intQueue(5);
    intQueue.push(1);
    intQueue.push(2);
    intQueue.push(3);
    intQueue.printItems();
    cout << "Dequeued from intQueue: " << intQueue.pop() << endl;
    intQueue.printItems();
    cout << "Is intQueue empty? " << intQueue.isEmpty() << endl;
    intQueue.clearItems();
    cout << "Is intQueue empty after clear? " << intQueue.isEmpty() << endl;
    cout << "---------------------------------------------" << endl;

    // Using Queue with Strings
    MyQueue<string> stringQueue(5);
    stringQueue.push("Hello");
    stringQueue.push("World");
    stringQueue.printItems();
    cout << "Dequeued from stringQueue: " << stringQueue.pop() << endl;
    stringQueue.printItems();
    cout << "---------------------------------------------" << endl;

    // Using Queue with Rectangles
    MyQueue<Rectangle> rectangleQueue(5);
    rectangleQueue.push(Rectangle(2, 3));
    rectangleQueue.push(Rectangle(4, 5));
    rectangleQueue.printItems();
    Rectangle r2 = rectangleQueue.pop();
    cout << "Dequeued rectangle has dimensions: Length=" << r2.getLength() << ", Width=" << r2.getWidth() << endl;
    rectangleQueue.printItems();

    Rectangle rect;
    rect.setLength(10);
    rect.setWidth(20);
    cout << "Rectangle with length " << rect.getLength() << " and width " << rect.getWidth() << " has area: " << rect.getArea() << endl;

    return 0;
}
