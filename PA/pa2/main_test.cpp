#include <iostream>
#include <cstring>
#include "user.h"
#include "transaction.h"
#include "blockchain.h"
#include "consensus.h"
#include "timestamp.h"
using namespace std;

int main() {
    cout << "//==============================================//" << endl;
    cout << "//         PART 1: TIMESTAMP FUNCTIONS          //" << endl;
    cout << "//==============================================//" << endl;
    cout << endl;

    Timestamp* timestamp = new Timestamp();
    char* timeStr = timestamp->getTime();
    cout << "init time is " << timeStr << endl;
    delete [] timeStr;
    timestamp->updateTime();
    timeStr = timestamp->getTime();
    cout << "current time is " << timeStr << endl;
    delete [] timeStr;
    timestamp->updateTime();
    timeStr = timestamp->getTime();
    cout << "current time is " << timeStr << endl;
    delete [] timeStr;
        
    cout << endl;
    cout << "//==============================================//" << endl;
    cout << "//            PART 2: USER FUNCTIONS            //" << endl;
    cout << "//==============================================//" << endl;
    cout << endl;

    User* testUser = new User("Test", 7, 23, 187);
    cout << "User has name " << testUser->getName() << ", e = " << testUser->getPublicKey() << ", days = " << testUser->getDays() << ", N = " << testUser->getModulus() << endl;
    testUser->updateDays();
    cout << "Now the user has " << testUser->getDays() << endl;
    testUser->resetDays();
    cout << "Now the user has " << testUser->getDays() << endl;
    testUser->updateDays();
    cout << "Now the user has " << testUser->getDays() << endl;

    cout << endl;
    cout << "//==============================================//" << endl;
    cout << "//        PART 3: TRANSACTION FUNCTIONS         //" << endl;
    cout << "//==============================================//" << endl;
    cout << endl;

    User* testUser2 = new User("Test2", 5, 53, 299);
    Transaction* testTransaction = new Transaction(testUser, testUser2, 1);
    cout << "Transaction is signed: " << testTransaction->verifyTransaction() << endl;
    testTransaction->printTransaction();

    cout << endl;
    cout << "//==============================================//" << endl;
    cout << "//           PART 4: BLOCK FUNCTIONS            //" << endl;
    cout << "//==============================================//" << endl;
    cout << endl;

    User* testUser3 = new User("Test", 7, 23, 187);
    User* testUser4 = new User("Test2", 5, 53, 299);
    Block* testBlock = new Block();
    Transaction* testTransaction2 = new Transaction(testUser3, testUser4, 1);
    Transaction* testTransaction3 = new Transaction(testUser4, testUser3, 3);
    testBlock->addTransaction(testTransaction2);
    testBlock->addTransaction(testTransaction3);
    testBlock->printBlock();

    cout << endl;
    cout << "//==============================================//" << endl;
    cout << "//         PART 5: BLOCKCHAIN FUNCTIONS         //" << endl;
    cout << "//==============================================//" << endl;
    cout << endl;
    Blockchain* testBlockchain = new Blockchain;
    testBlock->setTimestamp(timestamp->getTime());
    testBlockchain->publishBlock(*testBlock, HASH_MODULO);
    testBlockchain->printBlockchain(testBlockchain->findTail()); 

    cout << endl;
    cout << "//==============================================//" << endl;
    cout << "//          PART 6: CONSENSUS FUNCTIONS         //" << endl;
    cout << "//==============================================//" << endl;
    cout << endl;
    UserPool* testUserPool = new UserPool;
    testUserPool->addUser(new User("Alice", 7, 23, 187));
    testUserPool->addUser(new User("Bob", 5, 53, 299));
    testUserPool->addUser(new User("Charles", 13, 61, 851));
    User* validator = testUserPool->getValidator();
    cout << "The expected validator is " << testUserPool->getUser(2)->getName() << endl;
    cout << "The validator is " << validator->getName() << endl;

    delete timestamp;
    delete testUser;
    delete testUser2;
    delete testUser3;
    delete testUser4;
    delete testBlockchain;
    delete testUserPool;
}