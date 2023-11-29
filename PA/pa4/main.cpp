#include <iostream>
#include <list>
#include <fstream>
#include "opendatabase.h"
#include "chaindatabase.h"
#include "datatype.h"
#include "bst.h"
using namespace std;

int main(int argc, char* argv[]) {
    cout << boolalpha;
    Directory* dir;

    if (argc != 2) {
        cout << "Please specify the input filename!" << endl;
        exit(1);
    }

    cout << "Select the directory hashing type: " << endl;
    cout << "1: Open addressing with linear probing" << endl;
    cout << "2: Open addressing with quadratic probing" << endl;
    cout << "3: Open addressing with double hashing (h2(K) = R - K % R)" << endl;
    cout << "4: Linked list chaining" << endl;
    int choice;
    cin >> choice;
    const int DATABASE_CAPACITY = 20;
    switch (choice) {
        case 1:
            dir = new Directory{new OpenDatabase<LinearProbing>(DATABASE_CAPACITY)};
            break;
        case 2:
            dir = new Directory{new OpenDatabase<QuadraticProbing>(DATABASE_CAPACITY)};
            break;
        case 3:
            dir = new Directory{new OpenDatabase<DoubleHashing<17>>(DATABASE_CAPACITY)};
            break;
        case 4:
            dir = new Directory{new ChainDatabase(DATABASE_CAPACITY)};
            break;
        default:
            cout << "Invalid choice, exiting." << endl;
            exit(1);
    }

    fstream file {argv[1]};

    string name;
    unsigned int number;
    list<Person> pList{};
    while (file >> name >> number) {
        Person p {name.substr(0, name.size() - 1), number};
        if (dir->addPerson(p)) {
            pList.push_back(p);
        }
    }

    dir->print();

    for (list<Person>::iterator it = pList.begin(); it != pList.end(); ++it) {
        cout << (it->name) << "'s phone number: " << dir->getPhoneNumber(it->name) << endl;
    }
    cout << "Wxyz's phone number: " << dir->getPhoneNumber("Wxyz") << endl;

    for (list<Person>::iterator it = pList.begin(); it != pList.end(); ++it) {
        cout << (*it) << " removed: " << dir->removePerson(*it) << endl;
    }

    for (list<Person>::iterator it = pList.end(); it != pList.begin();) {
        --it;
        bool added = dir->addPerson(*it);
        cout << (*it) << " added: " << added << endl;
    }

    for (list<Person>::iterator it = pList.begin(); it != pList.end(); ++it) {
        bool added = dir->addPerson(*it);
        cout << (*it) << " is not added again: " << !added << endl;
    }

    dir->print();

    for (list<Person>::iterator it = pList.end(); it != pList.begin();) {
        --it;
        cout << (*it) << " removed: " << dir->removePerson(*it) << endl;
    }

    dir->print();

    delete dir;
}