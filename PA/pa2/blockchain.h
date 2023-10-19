#ifndef __BLOCKCHAIN_H__
#define __BLOCKCHAIN_H__

#include "transaction.h"
#include "consensus.h"

const int MAX_TRANSACTIONS = 10;

class Block {
	private:
		unsigned int prevBlockDigest;
		Transaction* transactions[MAX_TRANSACTIONS];
		int numTransactions;	
		unsigned int digest;
		// new data members
		char* miner;
		char* timestamp;

	public:
		Block();
		~Block();

		// Provided accessor/mutator functions
		unsigned int getPrevBlockDigest() const { return prevBlockDigest; }
		void setPrevBlockDigest(unsigned int prevBlockDigest) { this->prevBlockDigest = prevBlockDigest; }
		int getNumTransactions() const { return numTransactions; }
		unsigned int getDigest() const { return digest; }
		void setDigest(unsigned int digest) { this->digest = digest; }
		char* getMiner() const { return miner; }
		char* getTimestamp() const { return timestamp; }
		void setTimestamp(char* timestamp) { this->timestamp = timestamp; }

		// To be implemented
		void setMinerFromUserPool(UserPool* pool);
		void addTransaction(Transaction* transaction);
		unsigned int hashBlock() const;
		bool verifyBlock() const;
		void printBlock() const;
};

class Blockchain {
	private:
		Block** blocks;
		int numBlocks;

	public:
		Blockchain();
		~Blockchain();

		// Provided accessor functions
		int getNumBlocks() const { return numBlocks; }

		// To be implemented
		void addBlock(Block& block);
		void publishBlock(Block& block, unsigned int digest);
		Block* findBlock(unsigned int digest) const;
		Block* findTail() const;
		void printBlockchain(Block* tail) const;
};


#endif // __BLOCKCHAIN_H__
