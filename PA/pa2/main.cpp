#include <iostream>
#include <cstring>
#include "user.h"
#include "transaction.h"
#include "blockchain.h"
#include "consensus.h"
#include "timestamp.h"
using namespace std;

int main() {
	cout << "Welcome to the C++ Blockchain Ledger!" << endl;
	UserPool* userPool = new UserPool;

	Blockchain* blockchain = new Blockchain;
	Block* curBlock = new Block();
	Timestamp* timestamp = new Timestamp();
		
	int choice = 0;
	do {
		cout << "Select an option:" << endl;
		cout << "0: Exit" << endl;
		cout << "1: Register user" << endl;
		cout << "2: Perform transaction" << endl;
		cout << "3: View current block" << endl;
		cout << "4: Publish block" << endl;
		cout << "5: View entire blockchain" << endl;
		cout << "6: View user days at stake" << endl;
		cout << "Your selection: ";

		cin >> choice;
		cout << endl;

		if (choice < 0 || choice > 6 ) {
			cout << "Invalid choice!" << endl;
			continue;
		}

		switch (choice) {
			case 1: // register user
				{
					if (userPool->getNumUsers() == MAX_USERS) {
						cout << "Cannot register more users." << endl;
						break;
					}

					string name;
					unsigned int p, q, e, tokens;
					cout << "Input user name:" << endl;
					cin >> name;
					do {
						cout << "Choose a prime number:" << endl;
						cin >> p;
						if (!isPrime(p)) {
							cout << "This is not a prime number, please try again." << endl;
							continue;
						}
						else
							break;
					} while (true);
					do {
						cout << "Choose another prime number:" << endl;
						cin >> q;
						if (!isPrime(q)) {
							cout << "This is not a prime number, please try again." << endl;
							continue;
						}
						else
							break;
					} while (true);

					unsigned int N = p * q;
					unsigned int L = (p-1) * (q-1);

					do {
						cout << "Choose the public key:" << endl;
						cin >> e;
						if (gcd(e, L) != 1) {
							cout << "The public key is not co-prime with N's totient number." << endl;
							continue;
						}
						else
							break;
					} while (true);

					unsigned int d = inverseMod(e, L);
					cout << "The public key is: N = " << N << ", e = " << e << endl;
					cout << "The private key is: d = " << d << " (keep it secret!)" << endl;
					
					userPool->addUser(new User(name.c_str(), e, d, N));
				}
				break;
			case 2:	//Perform transaction
				{
					if (userPool->getNumUsers() <= 1) {
						cout << "Not enough registered users to make transactions!" << endl;
						break;
					}

					User *sender, *receiver;
					int amount;
					int selection;

					do {
						cout << "Select the sender:" << endl;
						for (int i = 0; i < userPool->getNumUsers(); ++i)
							cout << i << ": " << userPool->getUser(i)->getName() << endl;
						cout << "Your selection: ";

						cin >> selection;
						cout << endl;

						if (selection < 0 || selection >= userPool->getNumUsers()) {
							cout << "Invalid selection!" << endl;
							continue;
						}
						else {
							sender = userPool->getUser(selection);
							break;
						}
					} while (true);

					do {
						cout << "Select the receiver:" << endl;
						for (int i = 0; i < userPool->getNumUsers(); ++i)
							cout << i << ": " << userPool->getUser(i)->getName() << endl;
						cout << "Your selection: ";

						cin >> selection;
						cout << endl;

						if (selection < 0 || selection >= userPool->getNumUsers()) {
							cout << "Invalid selection!" << endl;
							continue;
						}
						else {
							receiver = userPool->getUser(selection);
							if (receiver == sender) {
								cout << "Cannot send money to yourself!" << endl;
								continue;
							}
							break;
						}
					} while (true);

					do {
						cout << "Type in the transaction amount: ";

						cin >> selection;
						cout << endl;

						if (selection < 0) {
							cout << "Cannot send negative money!" << endl;
							continue;
						}
						else {
							amount = selection;
							break;
						}
					} while (true);

					Transaction* t = new Transaction(sender, receiver, amount);
					curBlock->addTransaction(t);
				}
				break;
			case 3:	//View current block
				curBlock->printBlock();
				break;
			case 4:	//Publish block
				{	
					if (curBlock->getNumTransactions() == 0) {
						cout << "Block is empty, cannot be published." << endl;
						break;
					}
					int digest;
					if (blockchain->getNumBlocks() == 0) {
						digest = HASH_MODULO;
					}
					else {
						do {
							cout << "Select the block digest to chain to: ";

							cin >> digest;
							cout << endl;

							if (!blockchain->findBlock(digest) && digest != HASH_MODULO) {
								cout << "The provided digest cannot be found!" << endl;
							}
							else
								break;
						} while (true);
						
					}
					curBlock->setMinerFromUserPool(userPool);
					timestamp->updateTime();
					curBlock->setTimestamp(timestamp->getTime());
					blockchain->publishBlock(*curBlock, digest);
					cout << "Published block with digest " << curBlock->getDigest() << ", connected to block digest " << curBlock->getPrevBlockDigest() << 
						", miner is " << curBlock->getMiner() << endl;
					curBlock = new Block();
					cout << endl;
				}
				break;
			case 5:
				if (blockchain->getNumBlocks() == 0) {
					cout << "Blockchain is empty!" << endl;
					break;
				}
				blockchain->printBlockchain(blockchain->findTail());
				break;
			case 6:
				if (userPool->getNumUsers() == 0) {
					cout << "User pool is empty!" << endl;
					break;
				}
				for (int i = 0; i<userPool->getNumUsers(); ++i)
					cout << userPool->getUser(i)->getName() << ": days at stake = " << userPool->getUser(i)->getDays() << endl;
				cout << endl;
				break;
			default:
				break;
		}

	} while (choice != 0);

	delete blockchain;
	delete curBlock;
	delete userPool;
	delete timestamp;

	return 0;
}