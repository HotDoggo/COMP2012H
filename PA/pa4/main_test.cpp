#include <iostream>
#include <list>
#include <fstream>
#include "opendatabase.h"
#include "chaindatabase.h"
#include "datatype.h"
#include "bst.h"
#include <vector>
using namespace std;

vector<Person> pList = {
    {"Adam", 54321089},
    {"Bethany", 56789012},
    {"Caleb", 32567700},
    {"Danny", 41457032},
    {"Eve", 23586789},
    {"Francis", 92031164},
    {"Gerald", 56789000},
    {"Harry", 31538930},
    {"Iris", 77777777},
    {"Jason", 55960212},
};

/*
                        15(15)
                14(14)
        12(12)
                        11(11)
                10(10)
8(8)
                        7(7)
                6(6)
                        5(5)
        4(4)
                2(2)
                        1(1)
*/
void test11() {
    BinarySearchTree<int, int> bst;
    vector<int> vals = {8, 4, 12, 2, 10, 6, 14, 1, 7, 11, 15, 5};
    for (int i=0; i<vals.size(); ++i) {
        bst.insert(vals[i], vals[i]);
    }
    bst.print();
}

/*
11 exists: true
13 exists: false
*/
void test12() {
    BinarySearchTree<int, int> bst;
    vector<int> vals = {8, 4, 12, 2, 10, 6, 14, 1, 7, 11, 15, 5};
    for (int i=0; i<vals.size(); ++i) {
        bst.insert(vals[i], vals[i]);
    }
    cout << "11 exists: " << bst.contains(11) << endl;
    cout << "13 exists: " << bst.contains(13) << endl;
}

/*
                        15(15)
                14(14)
        12(12)
                11(11)
8(8)
                        7(7)
                6(6)
                        5(5)
        4(4)
                1(1)
*/
void test13() {
    BinarySearchTree<int, int> bst;
    vector<int> vals = {8, 4, 12, 2, 10, 6, 14, 1, 7, 11, 15, 5};
    for (int i=0; i<vals.size(); ++i) {
        bst.insert(vals[i], vals[i]);
    }
    bst.remove(2);
    bst.remove(10);
    bst.print();
}

/*
                15(15)
        14(14)
                        11(11)
                10(10)
8(8)
                        7(7)
                6(6)
        5(5)
                2(2)
                        1(1)
*/
void test14() {
    BinarySearchTree<int, int> bst;
    vector<int> vals = {8, 4, 12, 2, 10, 6, 14, 1, 7, 11, 15, 5};
    for (int i=0; i<vals.size(); ++i) {
        bst.insert(vals[i], vals[i]);
    }
    bst.remove(4);
    bst.remove(12);
    bst.print();
}

/*
                        88(15)
                59(14)
        7(12)
                        121(11)
                100(10)
64(8)
                        49(7)
                36(6)
                        25(5)
        16(4)
                        9(3)
                4(2)
min key: 2
value of key 8: 64
*/
void test15() {
    BinarySearchTree<int, int> bst;
    vector<int> vals = {8, 4, 12, 2, 10, 6, 14, 3, 7, 11, 15, 5};
    for (int i=0; i<vals.size(); ++i) {
        bst.insert(vals[i], vals[i] * vals[i] % 137);
    }
    bst.print();
    cout << "min key: " << bst.findMin() << endl;
    cout << "value of key 8: " << bst.getValue(8) << endl;
}

/*
Added Adam: true
Added Bethany: true
Added Caleb: true
Added Danny: true
Added Eve: true
Added Francis: true
Added Gerald: true
Added Harry: true
Added Iris: true
Added Jason: true
                Harry(18)
        Bethany(15)
Gerald -> Caleb -> Adam(11)
                        Francis(10)
                Eve(8)
                        Jason -> Iris(7)
        Danny(6)
*/
void test21() {
    ChainDatabase db {20};
    for (int i=0; i<pList.size(); ++i) {
        cout << "Added " << pList[i].name << ": " << db.addPerson(pList[i]) << endl;
    }
    db.print();
}

/*
Re-added Francis: false
*/
void test22() {
    ChainDatabase db {20};
    for (int i=0; i<pList.size(); ++i) {
        db.addPerson(pList[i]);
    }
    cout << "Re-added " << pList[5].name << ": " << db.addPerson(pList[5]) << endl;
}

/*
Francis's phone number: 92031164
Francis's actual phone number: 92031164
Wxyz's phone number: 0
*/
void test23() {
    ChainDatabase db {20};
    for (int i=0; i<pList.size(); ++i) {
        bool added = db.addPerson(pList[i]);
    }
    cout << pList[5].name << "'s phone number: " << db.getPhoneNumber(pList[5].name) << endl;
    cout << pList[5].name << "'s actual phone number: " << pList[5].phoneNumber << endl;
    cout << "Wxyz" << "'s phone number: " << db.getPhoneNumber("Wxyz") << endl;
}

/*
Removed Gerald: true
                Harry(18)
        Bethany(15)
Caleb -> Adam(11)
                        Francis(10)
                Eve(8)
                        Jason -> Iris(7)
        Danny(6)
*/
void test24() {
    ChainDatabase db {20};
    for (int i=0; i<pList.size(); ++i) {
        bool added = db.addPerson(pList[i]);
    }
    cout << "Removed " << pList[6].name << ": " << db.removePerson(pList[6]) << endl;
    db.print();
}

/*
Removed Caleb: true
                Harry(18)
        Bethany(15)
Gerald -> Adam(11)
                        Francis(10)
                Eve(8)
                        Jason -> Iris(7)
        Danny(6)
Re-added Caleb: true
                Harry(18)
        Bethany(15)
Caleb -> Gerald -> Adam(11)
                        Francis(10)
                Eve(8)
                        Jason -> Iris(7)
        Danny(6)
*/
void test25() {
    ChainDatabase db {20};
    for (int i=0; i<pList.size(); ++i) {
        bool added = db.addPerson(pList[i]);
    }
    cout << "Removed " << pList[2].name << ": " << db.removePerson(pList[2]) << endl;
    db.print();
    cout << "Re-added " << pList[2].name << ": " << db.addPerson(pList[2]) << endl;
    db.print();
}

/*
Linear probing sequence: 5 6 7 8 9
*/
void test31() {
    int key = 5;
    int index = 0;
    cout << "Linear probing sequence: ";
    for (int i=0; i<5; ++i) {
        cout << key + LinearProbing::offset(key, index) << " ";
    } 
    cout << endl;
}

/*
Quadratic probing sequence: 5 6 9 14 21
*/
void test32() {
    int key = 5;
    int index = 0;
    cout << "Quadratic probing sequence: ";
    for (int i=0; i<5; ++i) {
        cout << key + QuadraticProbing::offset(key, index) << " ";
    } 
    cout << endl;
}

/*
Double hashing probing sequence with R = 7: 5 7 9 11 13
*/
void test33() {
    int key = 5;
    int index = 0;
    cout << "Double hashing probing sequence with R = 7: ";
    for (int i=0; i<5; ++i) {
        cout << key + DoubleHashing<7>::offset(key, index) << " ";
    } 
    cout << endl;
}

/*
Added Adam: true
Added Bethany: true
Added Caleb: true
Added Danny: true
Added Eve: true
Added Francis: true
Added Gerald: true
Added Harry: true
Added Iris: true
Added Jason: true
                Harry(18)
        Bethany(15)
                        Gerald(13)
                Caleb(12)
Adam(11)
                        Francis(10)
                                Jason(9)
                Eve(8)
                        Iris(7)
        Danny(6)
*/
void test41() {
    OpenDatabase<LinearProbing> db {20};
    for (int i=0; i<pList.size(); ++i) {
        cout << "Added " << pList[i].name << ": " << db.addPerson(pList[i]) << endl;
    }
    db.print();
}

/*
Added Adam: true
Added Bethany: true
Added Caleb: true
Added Danny: true
Added Eve: true
Added Francis: true
Added Gerald: true
Added Harry: true
Added Iris: true
Added Jason: true
                Harry(18)
                        Jason(16)
        Bethany(15)
                Caleb(12)
Adam(11)
                        Francis(10)
                Eve(8)
                        Iris(7)
        Danny(6)
                Gerald(0)
*/
void test42() {
    OpenDatabase<QuadraticProbing> db {20};
    for (int i=0; i<pList.size(); ++i) {
        cout << "Added " << pList[i].name << ": " << db.addPerson(pList[i]) << endl;
    }
    db.print();
}

/*
Added Adam: true
Added Bethany: true
Added Caleb: true
Added Danny: true
Added Eve: true
Added Francis: true
Added Gerald: true
Added Harry: true
Added Iris: true
Added Jason: true
                        Gerald(19)
                                Harry(18)
                Caleb(16)
        Bethany(15)
                Jason(13)
Adam(11)
                        Francis(10)
                Eve(8)
                        Iris(7)
        Danny(6)
*/
void test43() {
    OpenDatabase<DoubleHashing<17>> db {20};
    for (int i=0; i<pList.size(); ++i) {
        cout << "Added " << pList[i].name << ": " << db.addPerson(pList[i]) << endl;
    }
    db.print();
}

/*
Re-added Francis: false
*/
void test44() {
    OpenDatabase<LinearProbing> db {20};
    for (int i=0; i<pList.size(); ++i) {
        db.addPerson(pList[i]);
    }
    cout << "Re-added " << pList[5].name << ": " << db.addPerson(pList[5]) << endl;
}

/*
Francis's phone number: 92031164
Francis's actual phone number: 92031164
Wxyz's phone number: 0
*/
void test45() {
    OpenDatabase<QuadraticProbing> db {20};
    for (int i=0; i<pList.size(); ++i) {
        bool added = db.addPerson(pList[i]);
    }
    cout << pList[5].name << "'s phone number: " << db.getPhoneNumber(pList[5].name) << endl;
    cout << pList[5].name << "'s actual phone number: " << pList[5].phoneNumber << endl;
    cout << "Wxyz" << "'s phone number: " << db.getPhoneNumber("Wxyz") << endl;
}

/*
Removed Gerald: true
                        Gerald [DELETED] (19)
                                Harry(18)
                Caleb(16)
        Bethany(15)
                Jason(13)
Adam(11)
                        Francis(10)
                Eve(8)
                        Iris(7)
        Danny(6)
*/
void test46() {
    OpenDatabase<DoubleHashing<17>> db {20};
    for (int i=0; i<pList.size(); ++i) {
        bool added = db.addPerson(pList[i]);
    }
    cout << "Removed " << pList[6].name << ": " << db.removePerson(pList[6]) << endl;
    db.print();
}

/*
Removed Caleb: true
                Harry(18)
        Bethany(15)
                        Gerald(13)
                Caleb [DELETED] (12)
Adam(11)
                        Francis(10)
                                Jason(9)
                Eve(8)
                        Iris(7)
        Danny(6)
Re-added Caleb: true
                Harry(18)
        Bethany(15)
                        Gerald(13)
                Caleb(12)
Adam(11)
                        Francis(10)
                                Jason(9)
                Eve(8)
                        Iris(7)
        Danny(6)
*/
void test47() {
    OpenDatabase<LinearProbing> db {20};
    for (int i=0; i<pList.size(); ++i) {
        bool added = db.addPerson(pList[i]);
    }
    cout << "Removed " << pList[2].name << ": " << db.removePerson(pList[2]) << endl;
    db.print();
    cout << "Re-added " << pList[2].name << ": " << db.addPerson(pList[2]) << endl;
    db.print();
}

int main() {
    cout << boolalpha;
    int choice;
    cin >> choice;
    
    switch (choice) {
        case 11: test11(); break;
        case 12: test12(); break;
        case 13: test13(); break;
        case 14: test14(); break;
        case 15: test15(); break;
        case 21: test21(); break;
        case 22: test22(); break;
        case 23: test23(); break;
        case 24: test24(); break;
        case 25: test25(); break;
        case 31: test31(); break;
        case 32: test32(); break;
        case 33: test33(); break;
        case 41: test41(); break;
        case 42: test42(); break;
        case 43: test43(); break;
        case 44: test44(); break;
        case 45: test45(); break;
        case 46: test46(); break;
        case 47: test47(); break;
        default:
            cout << "Unrecognized test case" << endl;
            break;
    }
}