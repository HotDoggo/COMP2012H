#ifndef MYSTACK_H
#define MYSTACK_H

// TODO: Complete the definition of the template MyStack class.
// You may refer to MyQueue.h as example.
// Note that some data members are different - read MyStack.cpp
// to find what data members the class should have.
template <typename T>
class MyStack
{
private:
    // Maximum number of items the Stack can hold
    int capacity;
    // A dynamic array storing the items
    T *items;
    // front: the index of the "front" item
    // back: the index of the "back" item
    // count: how many items are in the Stack
    int topIndex;

public:
    // Constructor
    // The keyword "explicit" prevents implicit conversion, e.g. MyStack q = 5;
    explicit MyStack(int capacity);
    // Destructor
    ~MyStack();

    // Add (push) an item into the Stack.
    // If the Stack is full, an error message is printed and the program exits.
    // For a Stack, new items should be inserted to the back.
    void push(T item);

    // Remove (pop) an item from the Stack.
    // If the Stack is empty, an error message is printed and the program exits.
    // For a Stack, items should be removed from the front.
    T &pop();

    // Return true if the Stack is empty.
    bool isEmpty() const;

    // Return true if the Stack is full.
    bool isFull() const;

    // Print all items in the Stack, from front to back.
    void printItems() const;

    // Reset the Stack to the "empty" state.
    void clearItems();
};

#include "MyStack.tpp"

#endif
