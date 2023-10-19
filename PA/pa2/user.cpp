#include <iostream>
#include <cstring>
#include "user.h"
#include "transaction.h"
#include "math.h"
using namespace std;

/**
 * Construct the User instance with the given parameters.
*/
User::User(const char* name, unsigned int e, unsigned int d, unsigned int N) {
	
	// TODO

}

/**
 * Deallocate dynamic memory in this User instance. 
*/
User::~User() {
	
	// TODO

}

/**
 * Update the number of days at stake.
 * 
 * It is noted that the number of days increases only when the days does not exceed
 * the MAX_DAYS.
*/
void User::updateDays() {
	
	// TODO

}


/**
 * Reset the stake days.
*/
void User::resetDays() {
	
	// TODO

}

/**
 * Return the number of days at stake. 
*/
unsigned int User::getDays() const {
	
	// TODO

	return 0;
}

/**
 * Return the signature of the transaction.
 * If the transaction's sender is not this user, output error message and return 0 instead.
*/
unsigned int User::signTransaction(const Transaction& transaction)
{
	if (false) { // TODO
		cout << "User is not authorized to sign someone else's transaction!" << endl;
		return 0;
	}

	// TODO
	return 0;
}
