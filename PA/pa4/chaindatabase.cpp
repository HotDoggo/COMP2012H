#include "chaindatabase.h"

// This function is provided so that BinarySearchTree<unsigned int, ChainDBnode*>
// can print the values.
// Items in the same linked list are printed on the same line, separated by " -> "
std::ostream& operator<<(std::ostream& os, ChainDBnode* node) {
    os << node->person;
    if (node->next) {
        os << " -> " << node->next;
    }
    return os;
}

// Provided constructor
ChainDatabase::ChainDatabase(int capacity): Database(capacity), tree() {}

// This function is provided to print the tree for visualizing
void ChainDatabase::print() const
{
    tree.print();
}

// TODO: Implement ChainDatabase's member functions

