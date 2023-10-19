#include <iostream>
#include "transaction.h"
#include "user.h"
#include "math.h"
using namespace std;

/**
* Construct a new Transaction
*
* Assign the sender, receiver, and amount according to the input.
* Remember to sign the transaction by the sender here.
*/
Transaction::Transaction(User* sender, User* receiver, unsigned int amount) {
	
	// TODO

}

// The functions below are all from PA1, you can copy from the solution and make adjustments

unsigned int Transaction::hashTransaction() const {
	
	// TODO

	return 0;
}

bool Transaction::verifyTransaction() const {
	
	// TODO

	return false;
}

// This function is given and should not be modified.
void Transaction::printTransaction() const {
	cout << sender->getName() << " pays " << receiver->getName() << " " << amount << " units. Signature: " << signature << endl;
}