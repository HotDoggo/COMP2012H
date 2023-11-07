#include <iostream>
using namespace std;

// Constructor
// topIndex is the index of the top item.
template <typename T>
MyQueue<T>::MyQueue(int capacity) : capacity(capacity), front(0), back(-1), count(0)
{
    items = new T[capacity];
}

// Destructor
template <typename T>
MyQueue<T>::~MyQueue()
{
    delete[] items;
}

template <typename T>
void MyQueue<T>::push(T item)
{
    if (isFull())
    {
        cout << "ERROR: Queue is full" << endl;
        exit(0);
    }
    back = (back + 1) % capacity;
    count++;
    this->items[back] = item;
}

template <typename T>
T &MyQueue<T>::pop()
{
    if (isEmpty())
    {
        cout << "ERROR: Queue is empty" << endl;
        exit(0);
    }
    T &item = items[front];
    front = (front + 1) % capacity;
    count--;
    return item;
}

// Return true if the Queue is empty.
template <typename T>
bool MyQueue<T>::isEmpty() const
{
    return (count == 0);
}

// Return true if the Queue is full.
template <typename T>
bool MyQueue<T>::isFull() const
{
    return count == capacity;
}

// Print all items in the Queue, from top to bottom.
template <typename T>
void MyQueue<T>::printItems() const
{
    for (int i = 0; i < count; i++)
    {
        cout << this->items[(front + i) % capacity] << endl;
    }
}

// Reset the Queue to the "empty" state.
template <typename T>
void MyQueue<T>::clearItems()
{
    front = 0;
    back = -1;
    count = 0;
}
