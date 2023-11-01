#ifndef __IMPLEMENTATION_H__
#define __IMPLEMENTATION_H__

#include "definition.h"
#include <cstring>

#include <iostream>
using namespace std;

//==============================================//
//        PART 1: MATHEMATICAL FUNCTIONS        //
//==============================================//

/**
 * Determines whether the input number n is a prime or not.
 * n is unsigned int - can be from 0 to 2^32 - 1
 *
 * @return true if n is a prime number, false otherwise.
 */
bool isPrime(unsigned int n)
{
	if (n <= 1)
		return false;
	int d = 2;
	while (d * d < n)
	{
		if (n % d == 0)
		{
			return false;
		}
		++d;
	}
	return true;
}

/**
 * Calculates the Greatest Common Divisor of 2 unsigned integers.
 * You may refer to Euclid's algorithm: https://en.wikipedia.org/wiki/Euclidean_algorithm
 *
 * @return The GCD of the 2 parameters.
 */
unsigned int gcd(unsigned int a, unsigned int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

/**
 * Calculates the modular multiplicative inverse of n with respect to modulo m.
 * This means if the return value is d, we have (d * n) mod m = 1.
 * If n has no inverse modulo m, output error message and return 0.
 * You may refer to the extended Euclid's algorithm: https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Modular_integers
 *
 * @return The inverse modulo m of n. If an inverse does not exist, return 0.
 */
unsigned int inverseMod(unsigned int n, unsigned int m)
{
	int inv = 0;
	int invNext = 1;
	int remainder = m;
	int remainderNext = n;

	while (remainderNext != 0)
	{
		int quotient = remainder / remainderNext;
		int temp = inv;
		inv = invNext;
		invNext = temp - quotient * invNext;
		temp = remainder;
		remainder = remainderNext;
		remainderNext = temp - quotient * remainderNext;
	}

	if (remainder > 1)
	{
		cout << "Error: " << n << " is not invertible mod " << m << "." << endl;
		return 0;
	}
	if (inv < 0)
		inv = inv + m;

	return inv;
}

/**
 * Calculates the power p of n modulo m.
 * In other words: powMod(n, p, m) = (n ^ p) mod m
 *
 * @returns The result of the calculation.
 */
unsigned int powMod(unsigned int n, unsigned int p, unsigned int m)
{
	unsigned int maxPowOfTwo = 0;
	unsigned int powOfTwo = 1;
	while (powOfTwo <= p)
	{
		powOfTwo *= 2;
		maxPowOfTwo += 1;
	}

	int *modPows = new int[maxPowOfTwo];
	modPows[0] = n % m;
	for (int i = 1; i < maxPowOfTwo; ++i)
	{
		modPows[i] = (modPows[i - 1] * modPows[i - 1]) % m;
	}

	unsigned int result = 1;
	for (int i = 0; i < maxPowOfTwo; ++i)
	{
		if (p % 2)
			result = (result * modPows[i]) % m;
		p /= 2;
	}

	delete[] modPows;
	return result;
}

//==============================================//
//            PART 2: USER FUNCTIONS            //
//==============================================//

/**
 * Dynamically allocate a User instance with the given parameters.
 *
 * @return Pointer to a dynamic allocated User instance.
 */
User *createUser(char *name, unsigned int e, unsigned int d, unsigned int N)
{
	return new User{name, e, d, N};
}

//==============================================//
//        PART 3: TRANSACTION FUNCTIONS         //
//==============================================//

/**
 * Calculates the hash value of a transaction,
 * which is the sum of the hash values of the sender's name, receiver's name, and transaction amount.
 * The sum should be modulo HASH_MODULO.
 *
 * @returns The hash value of a transaction using the above formula.
 */
unsigned int hashTransaction(const Transaction &transaction)
{
	return (hashString(transaction.sender->name) + hashString(transaction.receiver->name) + transaction.amount) % HASH_MODULO;
}

/**
 * Signs a transaction as valid.
 * For simplicity, we let the signee be a parameter of a function. In reality, we need to make sure only the signee can call this function with the parameter being themselves.
 *
 * If the signee is not the transaction's sender, output error message and exit the function.
 * Otherwise, set transaction's signature to be the signee's digital signature:
 *
 * signature = hash(transaction) ^ signee.private_key % signee.modulus
 */
void signTransaction(Transaction &transaction, const User &signee)
{
	if (strcmp(signee.name, transaction.sender->name))
	{
		cout << "User is not authorized to sign someone else's transaction!" << endl;
		return;
	}
	transaction.signature = powMod(hashTransaction(transaction), signee.private_key, signee.modulus);
}

/**
 * Verify that a transaction has been signed by checking the digital signature.
 * A transaction is valid if:
 *
 * signature ^ sender.public_key = hash(transaction)  (modulo sender.modulus)
 *
 * @return Whether the transaction has been signed with a valid signature.
 */
bool verifyTransaction(const Transaction &transaction)
{
	int check = powMod(transaction.signature, transaction.sender->public_key, transaction.sender->modulus);
	return (hashTransaction(transaction) - check) % transaction.sender->modulus == 0;
}

/**
 * Create a transaction where 'sender' sends 'amount' units to 'receiver'.
 * Dynamically allocate a Transaction instance with the given parameters, then let the sender sign it.
 *
 * @return Pointer to a dynamic allocated Transaction instance.
 */
Transaction *createTransaction(User *const sender, User *const receiver, int amount)
{
	Transaction *t = new Transaction{sender, receiver, amount};
	signTransaction(*t, *sender);
	return t;
}

//==============================================//
//           PART 4: BLOCK FUNCTIONS            //
//==============================================//

/**
 * Dynamically allocate an "empty" block to become the next block in the blockchain.
 * Set prevBlockDigest to be HASH_MODULO to represent "not connected to any block yet".
 * It will be modified when the block is published to the chain.
 *
 * @return Pointer to a dynamic allocated Block instance.
 */
Block *createBlock(int id = 0) { return new Block{HASH_MODULO, id, 0, {nullptr}, 0}; }

/**
 * Add a transaction to a block.
 *
 * If block capacity is reached, output error message and return.
 * If the transaction does not have valid signature, output error message and return.
 * Otherwise, set the newest entry in block's transaction list to the new transaction and increment the number of transactions.
 */
void addTransaction(Block &block, Transaction *const transaction)
{
	if (block.numTransactions == MAX_TRANSACTIONS)
	{
		cout << "Block capacity is full." << endl;
		return;
	}
	if (!verifyTransaction(*transaction))
	{
		cout << "Transaction signature verification failed." << endl;
		return;
	}
	block.transactions[block.numTransactions] = transaction;
	++block.numTransactions;
}

/**
 * Calculates the hash value of a block,
 * which is the sum of the hash values of all transactions, the digest and the block ID.
 * The sum should be modulo HASH_MODULO.
 *
 * @returns The hash value of a block using the above formula.
 */
unsigned int hashBlock(const Block &block)
{
	unsigned int sumTransaction = 0;
	for (int i = 0; i < block.numTransactions; ++i)
	{
		sumTransaction += hashTransaction(*block.transactions[i]);
	}
	return (sumTransaction + block.digest + block.id) % HASH_MODULO;
}

/**
 * Verify that a block has valid digest.
 * A valid block has hash value of 0.
 *
 * @return Whether the block has valid signature.
 */
bool verifyBlock(const Block &block)
{
	return hashBlock(block) == 0;
}

//==============================================//
//         PART 5: BLOCKCHAIN FUNCTIONS         //
//==============================================//

/**
 * Add a block to the blockchain.
 * Since Blockchain is a dynamic array of Blocks, expand the size of array as necessary.
 * Assume the block is already verified.
 */
void addBlock(Block &block, Blockchain &chain)
{
	Block **temp = new Block *[chain.numBlocks + 1];
	for (int i = 0; i < chain.numBlocks; ++i)
	{
		temp[i] = chain.blocks[i];
	}
	temp[chain.numBlocks++] = &block;
	delete[] chain.blocks;
	chain.blocks = temp;
}

/**
 * Publish a block to the blockchain, connecting to the block with the provided digest.
 * If block is empty, output error message and return. This has been done for you.
 *
 * Assume such a digest already exists, set the block's prevBlockDigest accordingly.
 * Then, the block digest needs to be calculated in order to be published.
 * Try every single values of block.digest until its hash value is 0.
 * Once a valid digest is found, set the block's digest and add it to the blockchain via addBlock().
 */
void publishBlock(Block &block, Blockchain &chain, unsigned int digest)
{
	if (block.numTransactions == 0)
	{
		cout << "Block is empty, cannot be published." << endl;
		return;
	}

	block.prevBlockDigest = digest;

	for (int d = 0; d < HASH_MODULO; ++d)
	{
		block.digest = d;
		if (verifyBlock(block))
		{
			break;
		}
	}

	addBlock(block, chain);
}

/**
 * Find the block with the given digest.
 * If there are multiple possible options (we assume this rarely/never happens), return the block with the lowest index.
 * If no such digest exists, return nullptr;
 *
 * @return A pointer to the Block in the blockchain with the provided digest
 */
Block *findBlock(const Blockchain &chain, unsigned int digest)
{
	for (int i = 0; i < chain.numBlocks; ++i)
	{
		if (chain.blocks[i]->digest == digest)
		{
			return chain.blocks[i];
		}
	}
	return nullptr;
}

/**
 * Find the tail block of the blockchain.
 * blocks[0] is the head, and we need to find the block with the longest connection to the starting Block.
 * If there are multiple possible options, return the block with the lowest ID.
 * If the blockchain is empty, return nullptr.
 *
 * Recommended algorithm:
 * - Create 2 arrays representing "current Tail blocks" and "possible Tail blocks".
 * - Put all blocks with no previous block (prevBlockDigest == HASH_MODULO) in "current Tail blocks". Set all remaining elements in both arrays to nullptr.
 * - Perform a while loop. In each iteration, loop over the blockchain and add any Block whose prevBlockDigest equals one of the "current Tails" digest to the "possible Tails".
 * 		- If there are no more such blocks, "current Tails" holds the blocks with the longest link to the head Block. Exit the loop.
 * 		- Otherwise, copy "possible Tails" to "current Tails" and go to next iteration.
 * - Return the item in "current Tails" with the smallest ID.
 *
 * @return A pointer to the Block in the blockchain that is "furthest away" from the starting Block.
 */
Block *findTail(const Blockchain &chain)
{
	if (chain.numBlocks == 0)
	{
		return nullptr;
	}

	int numPossibleTails = 0;
	Block **curTails = new Block *[chain.numBlocks];
	for (int i = 0; i < chain.numBlocks; ++i)
	{
		if (chain.blocks[i]->prevBlockDigest == HASH_MODULO)
		{
			curTails[numPossibleTails++] = chain.blocks[i];
		}
	}
	Block **possibleTails = new Block *[chain.numBlocks];
	for (int i = 0; i < chain.numBlocks; ++i)
	{
		if (i >= numPossibleTails)
			curTails[i] = nullptr;
		possibleTails[i] = nullptr;
	}

	do
	{
		numPossibleTails = 0;
		for (int i = 0; i < chain.numBlocks; ++i)
		{
			for (int j = 0; j < chain.numBlocks && curTails[j]; ++j)
			{
				if (chain.blocks[i]->prevBlockDigest == curTails[j]->digest)
				{
					possibleTails[numPossibleTails++] = chain.blocks[i];
					continue;
				}
			}
		}
		if (numPossibleTails)
		{
			delete[] curTails;
			curTails = possibleTails;
			possibleTails = new Block *[chain.numBlocks];
			for (int i = 0; i < chain.numBlocks; ++i)
			{
				possibleTails[i] = nullptr;
			}
		}
	} while (numPossibleTails);

	Block *ret = curTails[0];
	delete[] curTails;
	delete[] possibleTails;

	return ret;
}

/**
 * Recursive function to print the blockchain
 *
 * If tail has a previous block, do a recursive call to print the chain ending at that block.
 * Then, print the tail block using printBlock().
 */
void printBlockchain(const Blockchain &chain, Block *const tail)
{
	if (tail->prevBlockDigest != HASH_MODULO)
	{
		// This is not the first block, print the block preceeding this one
		printBlockchain(chain, findBlock(chain, tail->prevBlockDigest));
	}
	printBlock(*tail);
}

//==============================================//
//          PART 6: CLEANUP FUNCTIONS           //
//==============================================//

/**
 * Deallocate all dynamic memories in the block, as well as the block itself.
 * The block contains a list of dynamic allocated Transactions.
 * Note that you don't need to delete the Users in the Transactions - they are stored and handled in the main function.
 */
void clearBlock(Block *block)
{
	for (int i = 0; i < block->numTransactions; ++i)
	{
		delete block->transactions[i];
	}
	delete block;
}

/**
 * Deallocate all dynamic memories in the blockchain.
 * The blockchain contains dynamic allocated Blocks, so you need to call clearBlock accordingly.
 */
void clearBlockchain(Blockchain &chain)
{
	for (int i = 0; i < chain.numBlocks; ++i)
	{
		clearBlock(chain.blocks[i]);
	}
	delete[] chain.blocks;
}

#endif // __IMPLEMENTATION_H__
