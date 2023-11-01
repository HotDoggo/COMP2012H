#include <iostream>
using namespace std;

// TODO: Complete the implementation of the member functions
// of MyQueue class.
//
// You may refer to MyStack.tpp to see how the corresponding functions
// are implemented. Note that some data members are different:
// - front: the index of the "front" item. Items should be removed from the front.
// - back: the index of the "back" item. Items should be added to the back.
// - count: how many items are in the queue.
//
// The queue is implemented as a "circular" queue - if the array limit is reached,
// new items "loop" back to the beginning of the array. The queue is full when the
// array has no empty slots.
// Note that this means the starting value of front and back is not strictly enforced.
// A queue with a single item would have "front" = "back", since they refer to the same item.