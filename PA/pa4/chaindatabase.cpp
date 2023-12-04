#include "chaindatabase.h"

// This function is provided so that BinarySearchTree<unsigned int, ChainDBnode*>
// can print the values.
// Items in the same linked list are printed on the same line, separated by " -> "
std::ostream &operator<<(std::ostream &os, ChainDBnode *node)
{
    os << node->person;
    if (node->next)
    {
        os << " -> " << node->next;
    }
    return os;
}

// Provided constructor
ChainDatabase::ChainDatabase(int capacity) : Database(capacity), tree() {}

// This function is provided to print the tree for visualizing
void ChainDatabase::print() const
{
    tree.print();
}

// TODO: Implement ChainDatabase's member functions
ChainDatabase::~ChainDatabase()
{
    // ChainDBnode* cur =
}

unsigned int ChainDatabase::getPhoneNumber(const std::string &name) const
{
    unsigned int key = hashString(name) % getCapacity();

    if (!tree.contains(key))
        return 0;

    ChainDBnode *cur = tree.getValue(key);
    while (cur)
    {
        if (cur->person.name == name)
            return cur->person.phoneNumber;
        cur = cur->next;
    }

    return 0;
}

bool ChainDatabase::addPerson(const Person &person)
{
    if (getPhoneNumber(person.name))
        return false;

    unsigned int key = person.hash() % getCapacity();

    ChainDBnode *new_node = new ChainDBnode{person, nullptr};
    if (tree.contains(key))
    {
        new_node->next = tree.getValue(key);
        tree.remove(key);
    }

    tree.insert(key, new_node);

    return true;
}

bool ChainDatabase::removePerson(const Person &person)
{
    if (!getPhoneNumber(person.name))
        return false;

    unsigned int key = person.hash() % getCapacity();

    // case 1: head is removed
    ChainDBnode *cur = tree.getValue(key);
    if (cur->person == person)
    {
        if (cur->next == nullptr)
        {
            tree.remove(key);
        }
        else
        {
            ChainDBnode *temp = cur->next;
            tree.remove(key);
            tree.insert(key, temp);
        }
        delete cur;
        return true;
    }

    // case 2: anywhere else
    ChainDBnode *prev = cur;
    cur = cur->next;
    while (cur)
    {
        if (cur->person == person)
        {
            prev->next = cur->next;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }

    return false;
}