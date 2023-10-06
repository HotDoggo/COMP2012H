#include <iostream>
#include <cstring>
#include "implementation.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main()
{
	const int MAX_USERS = 10;
	int numUsers = 0;
	User *users[MAX_USERS];

	Blockchain blockchain{0, nullptr};
	Block *curBlock = createBlock();

	cout << "Welcome to the C++ Blockchain Ledger!" << endl;
	int choice = 0;
	do
	{
		cout << "Select an option:" << endl;
		cout << "0: Exit" << endl;
		cout << "1: Register user" << endl;
		cout << "2: Perform transaction" << endl;
		cout << "3: View current block" << endl;
		cout << "4: Publish block" << endl;
		cout << "5: View entire blockchain" << endl;
		cout << "Your selection: ";

		cin >> choice;
		cout << endl;

		if (choice < 0 || choice > 5)
		{
			cout << "Invalid choice!" << endl;
			continue;
		}

		switch (choice)
		{
		case 1:
		{
			if (numUsers == MAX_USERS)
			{
				cout << "Cannot register more users." << endl;
				break;
			}

			string name;
			unsigned int p, q, e;
			cout << "Input user name:" << endl;
			cin >> name;
			do
			{
				cout << "Choose a prime number:" << endl;
				cin >> p;
				if (!isPrime(p))
				{
					cout << "This is not a prime number, please try again." << endl;
					continue;
				}
				else
					break;
			} while (true);
			do
			{
				cout << "Choose another prime number:" << endl;
				cin >> q;
				if (!isPrime(q))
				{
					cout << "This is not a prime number, please try again." << endl;
					continue;
				}
				else
					break;
			} while (true);

			unsigned int N = p * q;
			unsigned int L = (p - 1) * (q - 1);

			do
			{
				cout << "Choose the public key:" << endl;
				cin >> e;
				if (gcd(e, L) != 1)
				{
					cout << "The public key is not co-prime with N's totient number." << endl;
					continue;
				}
				else
					break;
			} while (true);

			unsigned int d = inverseMod(e, L);
			cout << "The public key is: N = " << N << ", e = " << e << endl;
			cout << "The private key is: d = " << d << " (keep it secret!)" << endl;

			char *cname = new char[strlen(name.c_str()) + 1];
			strcpy(cname, name.c_str());
			users[numUsers++] = createUser(cname, e, d, N);
		}
		break;
		case 2:
		{
			if (numUsers <= 1)
			{
				cout << "Not enough registered users to make transactions!" << endl;
				break;
			}

			User *sender, *receiver;
			int amount;
			int selection;

			do
			{
				cout << "Select the sender:" << endl;
				for (int i = 0; i < numUsers; ++i)
					cout << i << ": " << users[i]->name << endl;
				cout << "Your selection: ";

				cin >> selection;
				cout << endl;

				if (selection < 0 || selection >= numUsers)
				{
					cout << "Invalid selection!" << endl;
					continue;
				}
				else
				{
					sender = users[selection];
					break;
				}
			} while (true);

			do
			{
				cout << "Select the receiver:" << endl;
				for (int i = 0; i < numUsers; ++i)
					cout << i << ": " << users[i]->name << endl;
				cout << "Your selection: ";

				cin >> selection;
				cout << endl;

				if (selection < 0 || selection >= numUsers)
				{
					cout << "Invalid selection!" << endl;
					continue;
				}
				else
				{
					receiver = users[selection];
					if (receiver == sender)
					{
						cout << "Cannot send money to yourself!" << endl;
						continue;
					}
					break;
				}
			} while (true);

			do
			{
				cout << "Type in the transaction amount: ";

				cin >> selection;
				cout << endl;

				if (selection < 0)
				{
					cout << "Cannot send negative money!" << endl;
					continue;
				}
				else
				{
					amount = selection;
					break;
				}
			} while (true);

			Transaction *t = createTransaction(sender, receiver, amount);
			addTransaction(*curBlock, t);
		}
		break;
		case 3:
			printBlock(*curBlock);
			break;
		case 4:
		{
			int digest;
			if (blockchain.numBlocks == 0)
			{
				digest = HASH_MODULO;
			}
			else
			{
				do
				{
					cout << "Select the block digest to chain to: ";

					cin >> digest;
					cout << endl;

					if (!findBlock(blockchain, digest) && digest != HASH_MODULO)
					{
						cout << "The provided digest cannot be found!" << endl;
					}
					else
						break;
				} while (true);
			}
			publishBlock(*curBlock, blockchain, digest);
			cout << "Published block with digest " << curBlock->digest << ", connected to block digest " << curBlock->prevBlockDigest << endl;
			curBlock = createBlock(blockchain.numBlocks);
		}
		break;
		case 5:
			if (blockchain.numBlocks == 0)
			{
				cout << "Blockchain is empty!" << endl;
				break;
			}
			printBlockchain(blockchain, findTail(blockchain));
			break;
		default:
			break;
		}

	} while (choice != 0);

	clearBlockchain(blockchain);
	clearBlock(curBlock);
	for (int i = 0; i < numUsers; ++i)
	{
		delete[] users[i]->name;
		delete users[i];
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}