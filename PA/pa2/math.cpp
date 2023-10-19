#include <iostream>
#include "math.h"
using namespace std;

unsigned long long next_num = 1;

/**
 * Determines whether the input number n is a prime or not.
 * n is unsigned int - can be from 0 to 2^32 - 1
 * 
 * @return true if n is a prime number, false otherwise.
*/
bool isPrime(unsigned int n) {
	if (n <= 1) return false;
    int d = 2;
    while (d * d < n) {
        if (n % d == 0) {
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
unsigned int gcd(unsigned int a, unsigned int b) {
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
unsigned int inverseMod(unsigned int n, unsigned int m) {
	int inv = 0;
	int invNext = 1;
    int remainder = m;
	int remainderNext = n;

    while (remainderNext != 0) {
        int quotient = remainder / remainderNext;
		int temp = inv;
		inv = invNext;
		invNext = temp - quotient * invNext;
		temp = remainder;
		remainder = remainderNext;
		remainderNext = temp - quotient * remainderNext;
	}

    if (remainder > 1) {
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
unsigned int powMod(unsigned int n, unsigned int p, unsigned int m) {
	unsigned int maxPowOfTwo = 0;
	unsigned int powOfTwo = 1;
	while (powOfTwo <= p) {
		powOfTwo *= 2;
		maxPowOfTwo += 1;
	}

	int* modPows = new int[maxPowOfTwo];
	modPows[0] = n % m;
	for (int i = 1; i < maxPowOfTwo; ++i) {
		modPows[i] = (modPows[i-1] * modPows[i-1]) % m;
	}

	unsigned int result = 1;
	for (int i = 0; i < maxPowOfTwo; ++i) {
		if (p % 2) result = (result * modPows[i]) % m;
		p /= 2;
	}

	delete [] modPows;
	return result;
}

// Provided hashing functions
unsigned int hashString(char* str) {
	int sum = 0;
	for (char* letter = str; *letter != '\0'; ++letter)
		sum = sum + static_cast<int>(*letter);
	return sum % HASH_MODULO; 
}

unsigned int randomPA2(unsigned int min, unsigned int max) {
	next_num = next_num * 1103515245 + 2011;
	return static_cast<unsigned int> (next_num / 65536) % (max-min) + min;
}