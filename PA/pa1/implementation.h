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
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
			return false;
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
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

// extended gcd to find inverse modulo
int extendedGCD(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}

	int x1, y1;
	int gcd = extendedGCD(b, a % b, x1, y1);

	x = y1;
	y = x1 - (a / b) * y1;

	return gcd;
}

/**
 * Calculates the modular multiplicative inverse of n with respect to modulo m.
 * This means if the return value is d, we have (d * n) mod m = 1.
 * If n has no inverse modulo m, output error message and return 0.
 * You may refer to the extended Euclid's algorithm: https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Modular_integers
 *
 * stolen code lmao https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
 *
 * @return The inverse modulo m of n. If an inverse does not exist, return 0.
 */
unsigned int inverseMod(unsigned int n, unsigned int m)
{
	int x, y;
	if (extendedGCD(n, m, x, y) != 1)
	{
		cout << "Error: " << n << " is not invertible mod " << m << "." << endl;
		return 0;
	}
	return (x % m + m) % m;
}

/**
 * Calculates the power p of n modulo m.
 * In other words: powMod(n, p, m) = (n ^ p) mod m
 *
 * stolen code lmao https://www.codespeedy.com/modular-exponentiation-in-cpp-power-in-modular/
 *
 * @returns The result of the calculation.
 */
unsigned int powMod(unsigned int n, unsigned int p, unsigned int m)
{
	int res = 1;
	n = n % m;

	if (n == 0)
		return 0;

	while (p > 0)
	{
		if (p & 1)
		{ // check if p is odd
			res = (res * n) % m;
		}

		p = p / 2;
		n = (n * n) % m;
	}
	return res;
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
	User *user = new User;
	user->name = new char[strlen(name) + 1];
	strcpy(user->name, name);
	user->public_key = e;
	user->private_key = d;
	user->modulus = N;
	return user;
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
	// int sum = transaction.amount;
	// int i = 0, j = 0;
	// while (transaction.sender->name[i] != '\0')
	// {
	// 	sum += transaction.sender->name[i++];
	// }
	// while (transaction.receiver->name[j] != '\0')
	// {
	// 	sum += transaction.receiver->name[j++];
	// }

	// return (sum % HASH_MODULO);

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
	if (strcmp(transaction.sender->name, signee.name))
	{ // TODO: Replace condition with "If the signee is not the transaction's sender"
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
	return powMod(transaction.signature, transaction.sender->public_key, transaction.sender->modulus) == hashTransaction(transaction) % transaction.sender->modulus;
}

/**
 * Create a transaction where 'sender' sends 'amount' units to 'receiver'.
 * Dynamically allocate a Transaction instance with the given parameters, then let the sender sign it.
 *
 * @return Pointer to a dynamic allocated Transaction instance.
 */
Transaction *createTransaction(User *const sender, User *const receiver, int amount)
{
	Transaction *transaction = new Transaction;
	transaction->sender = sender;
	transaction->receiver = receiver;
	transaction->amount = amount;
	User *signee = sender;
	signTransaction(*transaction, *signee);
	return transaction;
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
Block *createBlock(int id = 0)
{
	Block *block = new Block;
	block->prevBlockDigest = HASH_MODULO;
	block->id = id;
	block->numTransactions = 0;
	block->digest = 0;
	for (int i = 0; i < MAX_TRANSACTIONS; i++)
	{
		block->transactions[i] = nullptr;
	}
	return block;
}

/**
 * Add a transaction to a block.
 *
 * If block capacity is reached, output error message and return.
 * If the transaction does not have valid signature, output error message and return.
 * Otherwise, set the newest entry in block's transaction list to the new transaction and increment the number of transactions.
 */
void addTransaction(Block &block, Transaction *const transaction)
{
	if (block.numTransactions >= MAX_TRANSACTIONS)
	{ // TODO: Replace condition with "If block capacity is reached"
		cout << "Block capacity is full." << endl;
		return;
	}
	if (!verifyTransaction(*transaction))
	{ // TODO: Replace condition with "If the transaction does not have valid signature"
		cout << "Transaction signature verification failed." << endl;
		return;
	}

	block.transactions[block.numTransactions] = transaction;
	block.numTransactions++;
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
	int sum = block.digest + block.id;
	for (int i = 0; block.transactions[i] != nullptr; i++)
	{
		sum += hashTransaction(*block.transactions[i]);
	}
	return sum % HASH_MODULO;
}

/**
 * Verify that a block has valid digest.
 * A valid block has hash value of 0.
 *
 * @return Whether the block has valid signature.
 */
bool verifyBlock(const Block &block)
{
	return !hashBlock(block);
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
	if (chain.blocks == nullptr)
	{
		chain.blocks = new Block *[1];
		chain.numBlocks++;
		chain.blocks[0] = &block;
		return;
	}

	Block *temp = new Block[chain.numBlocks + 1];
	for (int i = 0; i < chain.numBlocks; i++)
	{
		temp[i] = *chain.blocks[i];
	}

	temp[chain.numBlocks] = block;

	delete[] chain.blocks;

	*chain.blocks = temp;
	delete[] temp;
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
	for (int i = 0; i < HASH_MODULO; i++)
	{
		block.digest = i;
		if (verifyBlock(block))
		{
			addBlock(block, chain);
			return;
		}
	}
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
	for (int i = 0; i < chain.numBlocks; i++)
	{
		if (chain.blocks[i]->digest == digest)
			return chain.blocks[i];
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
	if (!chain.numBlocks)
		return nullptr;

	// initialize arrays
	Block **current_tail_blocks = new Block *[chain.numBlocks];
	Block **possible_tail_blocks = new Block *[chain.numBlocks];

	int num_current_tail_blocks = 0, num_possible_tail_blocks;

	// step 1
	for (int i = 0; i < chain.numBlocks; i++)
	{
		if (chain.blocks[i]->prevBlockDigest == HASH_MODULO)
		{
			current_tail_blocks[num_current_tail_blocks++] = chain.blocks[i];
		}
	}

	while (1)
	{
		num_possible_tail_blocks = 0;

		// go through the blockchain, find the ones with a prev block digest, see if it equals to one of the current tail block digest
		for (int i = 0; i < chain.numBlocks; i++)
		{
			if (chain.blocks[i]->prevBlockDigest != HASH_MODULO)
			{
				for (int j = 0; j < num_current_tail_blocks; j++)
				{
					if (chain.blocks[i]->prevBlockDigest == current_tail_blocks[j]->digest)
					{
						possible_tail_blocks[num_possible_tail_blocks++] = chain.blocks[i];
					}
				}
			}
		}

		if (!num_possible_tail_blocks)
			break;

		current_tail_blocks = possible_tail_blocks;
		num_current_tail_blocks = num_possible_tail_blocks;
	}

	Block *tail_block = current_tail_blocks[0];

	// free the temp arrays
	for (int i = 0; i < chain.numBlocks; i++)
	{
		delete[] current_tail_blocks[i];
		delete[] possible_tail_blocks[i];
	}
	delete[] current_tail_blocks;
	delete[] possible_tail_blocks;

	return tail_block;
}

/**
 * Recursive function to print the blockchain
 *
 * If tail has a previous block, do a recursive call to print the chain ending at that block.
 * Then, print the tail block using printBlock().
 */
void printBlockchain(const Blockchain &chain, Block *const tail)
{
	if (tail->prevBlockDigest == HASH_MODULO)
		printBlock(*tail);
	else
		printBlockchain(chain, findBlock(chain, tail->prevBlockDigest));
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
	for (int i = 0; i < block->numTransactions; i++)
	{
		delete[] block->transactions[i];
	}
	delete[] block;
}

/**
 * Deallocate all dynamic memories in the blockchain.
 * The blockchain contains dynamic allocated Blocks, so you need to call clearBlock accordingly.
 */
void clearBlockchain(Blockchain &chain)
{
	for (int i = 0; i < chain.numBlocks; i++)
	{
		clearBlock(chain.blocks[i]);
	}
}

#endif // __IMPLEMENTATION_H__
