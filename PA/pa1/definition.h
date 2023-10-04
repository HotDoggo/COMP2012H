#ifndef __DEFINITION_H__
#define __DEFINITION_H__

#include <iostream>
using namespace std;

const int MAX_TRANSACTIONS = 10;
const unsigned int HASH_MODULO = 8191;

struct User {
	char* name;
	unsigned int public_key;
	unsigned int private_key;
	unsigned int modulus;
};

struct Transaction {
	User* sender;
	User* receiver;
	int amount;

	unsigned int signature;
};

struct Block {
	unsigned int prevBlockDigest;

	int id;
	int numTransactions;
	Transaction* transactions[MAX_TRANSACTIONS];

	unsigned int digest;
};

struct Blockchain {
	int numBlocks;
	Block** blocks;
};

// Provided hashing functions
unsigned int hashString(char* str) {
	int sum = 0;
	for (char* letter = str; *letter != '\0'; ++letter)
		sum = sum + static_cast<int>(*letter);
	return sum % HASH_MODULO; 
}

// Provided printing functions (you don't need to use these)
void printTransaction(const Transaction& transaction) {
	cout << transaction.sender->name << " pays " << transaction.receiver->name << " " << transaction.amount << " units. Signature: " << transaction.signature << endl;
}

void printBlock(const Block& block) {
	cout << "Block id: " << block.id << endl;
	cout << "Block digest: " << block.digest << endl;
	for (int i = 0; i < block.numTransactions; ++i) {
		cout << i+1 << ": ";
		printTransaction(*block.transactions[i]);
	}
	cout << endl;
}

#endif // __DEFINITION_H__
