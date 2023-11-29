#ifndef __DATATYPE_H__
#define __DATATYPE_H__

#include <iostream>
#include <string>

// This is a C++11 way of defining a compile-time constant; it otherwise behaves like a const int
constexpr int HASH_MODULO = 13466917;

// Helper function to hash a string into int
unsigned int hashString(std::string str);

/** A struct representing a Person
 * It contains the person's name and phone number.
 * You can assume every Person will have a unique name, and a non-zero phone number.
 *
 * Two helper functions are defined:
 * - operator==() to compare 2 Persons. It returns true only if both name and phone number are the same.
 * - hash() returns the hash value of this Person.
*/
struct Person {
    std::string name;
    unsigned int phoneNumber;

    bool operator==(const Person& person) const { return (name == person.name) && (phoneNumber == person.phoneNumber); }
    unsigned int hash() const { return hashString(name) % HASH_MODULO; }
};

// Helper function to print the name of Person
std::ostream& operator<<(std::ostream& os, const Person& person);

/**
 * Abstract class to represent the database of people and phone numbers.
 * 
 * The implementation classes will contain a BinarySearchTree with the corresponding template type.
 * This class also contains a capacity as a limit for the indexing key.
 * The value of keys in the tree can only be from 0 to capacity-1.
 * 
 * Class implementations will need to override the functions to add/remove a Person object,
 * and to find and retrieve the phone number for some specified name.
 * - addPerson() and removePerson() returns whether or not the operation was successful (whether the
 *  person has successfully been added to / removed from the tree).
 * - getPhoneNumber() returns 0 if the name is not in the database.
*/
class Database {
    private:
        int capacity;

    public:
        Database(int capacity): capacity(capacity) {}
        virtual ~Database() = default;

        virtual bool addPerson(const Person& person) = 0;
        virtual bool removePerson(const Person& person) = 0;
        virtual unsigned int getPhoneNumber(const std::string& name) const = 0;

        int getCapacity() const { return capacity; }
        
        virtual void print() const = 0;
};

/**
 * A wrapper class which holds a pointer to a Database. It does not know the specific implementation of the Database,
 * but it supports similar operations such that outer functions like main() can simply interact via this class.
*/
class Directory {
    private:
        Database* database;

    public:
        Directory(Database* database): database(database) {}
        ~Directory() { delete database; }

        bool addPerson(const Person& person);
        bool removePerson(const Person& person);
        unsigned int getPhoneNumber(const std::string& name) const;

        void print() const;
};

#endif // __DATATYPE_H__