#ifndef __MATH_H__
#define __MATH_H__

const unsigned int HASH_MODULO = 8191;

bool isPrime(unsigned int n);
unsigned int gcd(unsigned int a, unsigned int b);
unsigned int inverseMod(unsigned int n, unsigned int m);
unsigned int powMod(unsigned int n, unsigned int p, unsigned int m);
unsigned int hashString(char* str);
unsigned int randomPA2(unsigned int min, unsigned int max);

#endif  //__MATH_H__