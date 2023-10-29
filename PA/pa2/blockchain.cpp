#include <iostream>
#include <cstring>
#include "blockchain.h"
using namespace std;

/**
 * Construct an "empty" block. Refer to PA1 for the default value of data members.
 * Set miner and timestamp to nullptr.
 */
Block::Block() : prevBlockDigest(HASH_MODULO), transactions({nullptr}), numTransactions(0), digest(0), miner(nullptr), timestamp(nullptr)
{
}

/**
 * Deallocate all dynamic memories in the block, along with miner and timestamp.
 */
Block::~Block()
{
	for (int i = 0; i < numTransactions; i++)
	{
		delete transactions[i];
	}
	delete[] transactions;
	delete miner;
	delete timestamp;
	// TODO
}

/**
 * With the UserPool provided, find the validator User by calling getValidator().
 * Then, create a Transaction where the Pool Manager pays the validator 10 units.
 * Add this transaction to the block, and copy validator's name to the miner using strcpy.
 */
void Block::setMinerFromUserPool(UserPool *pool)
{
	strcpy(miner, pool->getValidator()->getName());
}

/**
 * Construct an empty blockchain.
 */
Blockchain::Blockchain()
{

	// TODO
}

/**
 * Deallocate all dynamic memories in the blockchain.
 * The blockchain contains dynamic allocated Blocks, so you need to call clearBlock accordingly.
 */
Blockchain::~Blockchain()
{

	// TODO
}

// The functions below are all from PA1, you can copy from the solution and make adjustments

/**
 * Add a transaction to the block.
 *
 * If block capacity is reached, output error message and return.
 * If the transaction does not have valid signature, output error message and return.
 * Otherwise, set the newest entry in block's transaction list to the new transaction and increment the number of transactions.
 */
void Block::addTransaction(Transaction *const transaction)
{
	if (false)
	{ // TODO: Condition
		cout << "Block capacity is full." << endl;
		return;
	}
	if (false)
	{ // TODO: Condition
		cout << "Transaction signature verification failed." << endl;
		return;
	}

	// TODO
}

/**
 * Calculates the hash value of the block,
 * which is the sum of the hash values of all transactions, the digest and timestamp's hash (instead of block ID).
 * The sum should be modulo HASH_MODULO.
 *
 * @return The hash value of a block using the above formula.
 */
unsigned int Block::hashBlock() const
{

	// TODO

	return 0;
}

/**
 * Verify that a block has valid digest.
 * A valid block has hash value of 0.
 *
 * @return Whether the block has valid signature.
 */
bool Block::verifyBlock() const
{

	// TODO

	return false;
}

// This function is given and should not be modified.
void Block::printBlock() const
{
	cout << "Block digest: " << digest << endl;
	if (miner)
		cout << "Block miner: " << miner << endl;
	if (timestamp)
		cout << "Block timestamp: " << timestamp << endl;

	for (int i = 0; i < numTransactions; ++i)
	{
		cout << i + 1 << ": ";
		transactions[i]->printTransaction();
	}
	cout << endl;
}

/**
 * Add a block to the blockchain.
 * Since Blockchain is a dynamic array of Blocks, expand the size of array as necessary.
 * Assume the block is already verified.
 */
void Blockchain::addBlock(Block &block)
{

	// TODO
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
void Blockchain::publishBlock(Block &block, unsigned int digest)
{
	if (block.getNumTransactions() == 0)
	{
		cout << "Block is empty, cannot be published." << endl;
		return;
	}

	// TODO
}

/**
 * Find the block with the given digest.
 * If there are multiple possible options (we assume this rarely/never happens), return the block with the lowest timestamp.
 * If no such digest exists, return nullptr;
 *
 * @return A pointer to the Block in the blockchain with the provided digest
 */
Block *Blockchain::findBlock(unsigned int digest) const
{

	// TODO

	return nullptr;
}

/**
 * Find the tail block of the blockchain.
 * blocks[0] is the head, and we need to find the block with the longest connection to the starting Block.
 * If there are multiple possible options, return the block with the lowest timestamp.
 * If the blockchain is empty, return nullptr.
 *
 * You are recommended to copy from the PA1 solution's corresponding function, then make necessary OOP changes.
 *
 * @return A pointer to the Block in the blockchain that is "furthest away" from the starting Block.
 */
Block *Blockchain::findTail() const
{

	// TODO

	return nullptr;
}

/**
 * Recursive function to print the blockchain
 *
 * If tail has a previous block, do a recursive call to print the chain ending at that block.
 * Then, print the tail block using printBlock().
 */
void Blockchain::printBlockchain(Block *tail) const
{

	// TODO
}
