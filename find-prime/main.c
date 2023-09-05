#include "sieve.h"
#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    Sieve *s = sieve_construct(n);

    sieve_find_prime(s);

    sieve_destroy(s);

    return 0;
}
