#include "opendatabase.h"

// This function is provided so that BinarySearchTree<unsigned int, OpenDBnode>
// can print the values.
// Items that are deleted will be marked "[DELETED]"
std::ostream& operator<<(std::ostream& os, const OpenDBnode& node) {
    os << node.person << (node.deleted ? " [DELETED] " : "");
    return os;
}
