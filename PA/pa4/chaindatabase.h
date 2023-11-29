#ifndef __CHAINDATABASE_H__
#define __CHAINDATABASE_H__

#include "datatype.h"
#include "bst.h"

/**
 * Implementation of the Database class, using chaining collision resolution.
 * Each node in the BinarySearchTree stores a linked list in the value field
 * (it actually just stores the head node).
 * 
 * Linked list node is defined as the ChainDBnode struct, which contains a Person
 * and the pointer to the next node. The last node in the list should have next
 * point to nullptr.
 * 
 * You need to implement the functions to add, remove or get the phone number of a name
 * stored in the database. The add and remove functions return true if the operation 
 * is successful, and false otherwise.
 * 
 * Recommended framework for add/remove:
 * - Check if the person's name is already in the database using getPhoneNumber(). If the name already exists,
 *   addPerson() should do nothing. If not, removePerson() should do nothing.
 * - Get the key to index into the tree by taking the person's hash modulo capacity.
 *   For getPhoneNumber(), use hashString() to calculate the hash value from the provided name.
 * - If the tree contains a node with that key, operate on the corresponding linked list:
 *  + addPerson(): Allocate a new ChainDBnode and add it to the beginning of the linked list. 
 *                 Note that the head node is returned by reference.
 *  + removePerson(): Remove the ChainDBnode with the specified person from the linked list and deallocate the node. 
 *                 If necessary, you also need to modify the head node. Additionally, if the linked list becomes empty, 
 *                 remove the TreeNode with the current key from the tree.
 * - Otherwise:
 *  + addPerson(): Insert the key value pair into the tree, where 'value' is a ChainDBnode holding the person representing
 *                 the head of the linked list.
 *  + removePerson(): Do nothing.
 * - Return true if the add/remove process was successful, and false otherwise. In other words, return true if and only if
 * the tree and/or any linked list is modified after add/remove.
 * 
 * getPhoneNumber() can follow a similar framework as above to find the node with the specified name, and return the phone number.
 * If the name cannot be found, return 0.
*/

struct ChainDBnode {
    Person person;
    ChainDBnode* next;
};

std::ostream& operator<<(std::ostream& os, ChainDBnode* node);

class ChainDatabase : public Database {
    private:
        BinarySearchTree<unsigned int, ChainDBnode*> tree;

    public:
        ChainDatabase(int capacity);

        virtual bool addPerson(const Person& person) override;
        virtual bool removePerson(const Person& person) override;
        virtual unsigned int getPhoneNumber(const std::string& name) const override;

        virtual void print() const override;
};

#endif // __CHAINDATABASE_H__