#ifndef __OPENDATABASE_H__
#define __OPENDATABASE_H__

#include "datatype.h"
#include "bst.h"
#include "probing.h"

/**
 * Implementation of the Database class, using open addressing collision resolution.
 * Each node in the BinarySearchTree stores a struct containing the Person, and
 * a boolean specifying whether this node is removed from the tree.
 * 
 * This class is a template class, with the type parameter determining the probing mechanism.
 * Type P can be one of the 3 classes defined in probing.h, all of which supports a static function
 * offset(int key, int& index), which returns the probing offset and increments the index.
 * In other words, the probing sequence is:
 * 
 *  h(person, i) = person.hash() + offset(person.hash(), i) % capacity
 * 
 * You need to implement the functions to add, remove or get the phone number of a name
 * stored in the database. The add and remove functions return true if the operation 
 * is successful, and false otherwise.
 * 
 * Recommended framework for add/remove:
 * - Check if the person's name is already in the database using getPhoneNumber(). If the name already exists,
 *   addPerson() should do nothing. If not, removePerson() should do nothing.
 * - Get the key to index into the tree by taking the person's hash modulo capacity.
 * - Perform a loop to find the node with the provided name/person, or the first node that is empty/deleted,
 *   according to the probing sequence. You need to use the parameter type P's offset() function to generate
 *   the probing sequence.
 *  + addPerson(): If an empty slot is found, insert a node into the tree using the current key and the provided Person.
 *                 If that slot instead has a 'deleted' node, modify its content to the provided Person and set 'deleted' to false.
 *  + removePerson(): If the person/name is found, set that node's 'deleted' to true.
 *  + The probing sequence ends when the key becomes the original value again. If this occurs, return false.
 * - Return true if the add/remove process was successful, and false otherwise. In other words, return true if and only if
 * the tree and/or any linked list is modified after add/remove.
 * 
 * getPhoneNumber() can follow a similar framework as above to find the node with the specified name, and return the phone number.
 * If the name cannot be found, return 0.
*/

struct OpenDBnode {
    Person person;
    bool deleted;
};

std::ostream& operator<<(std::ostream& os, const OpenDBnode& node);

template <typename P>
class OpenDatabase : public Database {
    private:
        BinarySearchTree<unsigned int, OpenDBnode> tree;

    public:
        OpenDatabase(int capacity): Database(capacity), tree() {}

        virtual bool addPerson(const Person& person) override;
        virtual bool removePerson(const Person& person) override;
        virtual unsigned int getPhoneNumber(const std::string& name) const override;

        virtual void print() const override;
};

#include "opendatabase.tpp"

#endif // __OPENDATABASE_H__