#ifndef __TRANSACTION_H__
#define __TRANSACTION_H__

#include "user.h"

class Transaction {
	private:
		User* sender;
		User* receiver;
		unsigned int amount;
		unsigned int signature;

	public:
		Transaction(User* sender, User* receiver, unsigned int amount);

		// Provided accessor functions
		char* getSenderName() const { return sender->getName(); }

		// To be implemented
		unsigned int hashTransaction() const;
		bool verifyTransaction() const;
		void printTransaction() const;
};

#endif // __TRANSACTION_H__
