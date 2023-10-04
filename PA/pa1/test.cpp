#include <iostream>
#include "implementation.h"
using namespace std;

int main()
{
    cout << "//==============================================//" << endl;
    cout << "//        PART 1: MATHEMATICAL FUNCTIONS        //" << endl;
    cout << "//==============================================//" << endl;
    cout << boolalpha << endl;

    cout << "7 is prime: " << isPrime(7) << endl;
    cout << "187 is prime: " << isPrime(187) << endl;
    cout << "10369 is prime: " << isPrime(10369) << endl;
    cout << endl;

    cout << "GCD of 48 and 36 is: " << gcd(48, 36) << endl;
    cout << "GCD of 120 and 91 is: " << gcd(120, 91) << endl;
    cout << endl;

    cout << "Inverse of 23 modulo 160 is: " << inverseMod(23, 160) << endl;
    cout << "Inverse of 61 modulo 198 is: " << inverseMod(61, 198) << endl;
    cout << endl;

    cout << "7 ^ 6 mod 23 = " << powMod(7, 6, 23) << endl;
    cout << "183 ^ 23 mod 187 = " << powMod(183, 23, 187) << endl;
    cout << endl;

    cout << "//==============================================//" << endl;
    cout << "//            PART 2: USER FUNCTIONS            //" << endl;
    cout << "//==============================================//" << endl;
    cout << endl;

    User *testUser = createUser((char *)"Test", 7, 23, 187);
    if (testUser)
    {
        cout << "User has name " << testUser->name << ", e = " << testUser->public_key << ", d = " << testUser->private_key << ", N = " << testUser->modulus << endl;
        delete testUser;
    }
    else
    {
        cout << "Unimplemented task." << endl;
    }
    cout << endl;

    cout << "//==============================================//" << endl;
    cout << "//        PART 3: TRANSACTION FUNCTIONS         //" << endl;
    cout << "//==============================================//" << endl;
    cout << endl;

    User alice{(char *)"Alice", 23, 7, 187};
    User bob{(char *)"Bob", 53, 5, 299};
    Transaction t{&alice, &bob, 1000};

    cout << "Transaction has hash " << hashTransaction(t) << endl;
    cout << "Transaction is signed: " << verifyTransaction(t) << endl;
    signTransaction(t, alice);
    cout << "Transaction is signed: " << verifyTransaction(t) << endl;
    cout << endl;

    Transaction *testTransaction = createTransaction(&bob, &alice, 2000);
    if (testTransaction)
    {
        printTransaction(*testTransaction);
        cout << "Transaction is signed: " << verifyTransaction(*testTransaction) << endl;
        delete testTransaction;
    }
    else
    {
        cout << "Unimplemented task." << endl;
    }
    cout << endl;

    cout << "//==============================================//" << endl;
    cout << "//           PART 4: BLOCK FUNCTIONS            //" << endl;
    cout << "//==============================================//" << endl;
    cout << endl;

    Block *testBlock = createBlock(5);
    if (testBlock)
    {
        printBlock(*testBlock);
        delete testBlock;
    }
    else
    {
        cout << "Unimplemented task." << endl;
    }

    Block b{0, 0, 1, {&t}, 0};
    Transaction t2{&bob, &alice, 500};
    signTransaction(t2, bob);
    addTransaction(b, &t2);
    printBlock(b);
    cout << "Block has hash " << hashBlock(b) << endl;
    // cout << b.digest << endl;
    cout << "Block is valid: " << verifyBlock(b) << endl;
    b.digest = 5185;
    // cout << b.digest << endl;
    cout << "Block is valid: " << verifyBlock(b) << endl;
    cout << endl;

    cout << "//==============================================//" << endl;
    cout << "//      PART 5: WHATEVER THE FUCK IM DOING      //" << endl;
    cout << "//==============================================//" << endl;
    cout << endl;

    Blockchain test{0, nullptr};
    Block *curBlock = createBlock();

    User A{(char *)"A", 23, 7, 187};
    User B{(char *)"B", 53, 5, 299};

    Transaction *temp = createTransaction(&A, &B, 100);
    signTransaction(*temp, A);
    addTransaction(*curBlock, temp);

    publishBlock(*curBlock, test, HASH_MODULO);
    printBlock(*curBlock);

    printBlock(*findTail(test));

    cout << curBlock->id << " " << curBlock->digest << endl;

    cout << endl;
    printBlockchain(test, findTail(test));
}