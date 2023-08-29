#ifndef _SIEVE_H_
#define _SIEVE_H_

typedef struct Sieve Sieve;

Sieve *sieve_construct(int n);

void sieve_destroy(Sieve *s);

void sieve_find_prime(Sieve *s);

#endif