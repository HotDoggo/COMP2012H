#ifndef __PROBING_H__
#define __PROBING_H__

/**
 * The classes representing Probing strategies.
 * Implement the offset() functions so that they can generate the correct probing sequence.
 * For double hashing, an extra parameter is needed for the second hashing function. It is stored
 * as a template non-type parameter.
 *
 * Note that an alternative way of implementing this is for OpenDatabase to store the function
 * directly using function pointer or lambda functions.
 */

class LinearProbing
{
public:
    static int offset(int key, int &index)
    {
        // TODO
        // Linear probing sequence: h(x, i) = x + offset(x, i) = x + i
        // index should be incremented as well
        int offset = index;
        index++;
        return offset;
    }
};

class QuadraticProbing
{
public:
    static int offset(int key, int &index)
    {
        // TODO
        // Quadratic probing sequence: h(x, i) = x + offset(x, i) = x + i^2
        // index should be incremented as well
        int offset = index * index;
        index++;
        return offset;
    }
};

template <unsigned int R>
class DoubleHashing
{
public:
    static int offset(int key, int &index)
    {
        // TODO
        // Double hashing probing sequence: h(x, i) = x + offset(x, i) = x + i*(R - x % R)
        // index should be incremented as well
        int offset = (R - (key % R)) * index;
        index++;
        return offset;
    }
};

#endif // __PROBING_H__