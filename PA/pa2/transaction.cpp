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
Transaction::Transaction(User *sender, User *receiver, unsigned int amount)
{
	this->sender = sender;
	this->receiver = receiver;
	this->amount = amount;
	this->signature = sender->signTransaction(*this);
}

// The functions below are all from PA1, you can copy from the solution and make adjustments

unsigned int Transaction::hashTransaction() const
{
	return (hashString(sender->getName()) + hashString(receiver->getName()) + amount) % HASH_MODULO;
}

bool Transaction::verifyTransaction() const
{
	int check = powMod(signature, sender->getPublicKey(), sender->getModulus());
	return (hashTransaction() - check) % sender->getModulus() == 0;
}

// This function is given and should not be modified.
void Transaction::printTransaction() const
{
	cout << sender->getName() << " pays " << receiver->getName() << " " << amount << " units. Signature: " << signature << endl;
}