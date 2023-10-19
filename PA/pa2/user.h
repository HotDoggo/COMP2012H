#ifndef __USER_H__
#define __USER_H__

const int MAX_DAYS = 10;

class Transaction;

class User {
	private:
		char* name;
		unsigned int public_key;
		unsigned int modulus;
		unsigned int private_key;
		// new data member
		unsigned int days;

	public:
		User(const char* name, unsigned int e, unsigned int d, unsigned int N);
		~User();

		// Provided accessor functions
		char* getName() const { return name; }
		unsigned int getPublicKey() const { return public_key; }
		unsigned int getModulus() const { return modulus; }

		// To be implemented
		void updateDays();
		void resetDays();
		unsigned int getDays() const;
		unsigned int signTransaction(const Transaction& transaction);
};

#endif // __USER_H__
