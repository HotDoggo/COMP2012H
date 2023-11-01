#include <iostream>
#include <cstring>
#include "user.h"
#include "transaction.h"
#include "math.h"
using namespace std;

/**
 * Construct the User instance with the given parameters.
 */
User::User(const char *name, unsigned int e, unsigned int d, unsigned int N)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	public_key = e;
	private_key = d;
	modulus = N;
	days = 1;
}

/**
 * Deallocate dynamic memory in this User instance.
 */
User::~User()
{
	delete[] name;
}

/**
 * Update the number of days at stake.
 *
 * It is noted that the number of days increases only when the days does not exceed
 * the MAX_DAYS.
 */
void User::updateDays()
{
	if (days < MAX_DAYS)
		days++;
}

/**
 * Reset the stake days.
 */
void User::resetDays()
{
	days = 0;
}

/**
 * Return the number of days at stake.
 */
unsigned int User::getDays() const
{
	return days;
}

/**
 * Return the signature of the transaction.
 * If the transaction's sender is not this user, output error message and return 0 instead.
 */
unsigned int User::signTransaction(const Transaction &transaction)
{
	if (strcmp(transaction.getSenderName(), name))
	{
		cout << "User is not authorized to sign someone else's transaction!" << endl;
		return 0;
	}
	return powMod(transaction.hashTransaction(), private_key, modulus);
}
