#include "sieve.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Sieve {
    bool *array;
    int size;
};

Sieve *sieve_construct(int n) {
    Sieve *s = malloc(sizeof(Sieve));

    s->size = n + 1;
    s->array = calloc(s->size, sizeof(int));

    return s;
}

void sieve_destroy(Sieve *s) {
    free(s->array);
    free(s);
}

void sieve_find_prime(Sieve *s) {
    int i = 2;
    while(true) {
        for(int aux = i; aux < s->size; aux++) {
            if(!(aux % i))
                s->array[aux] = true;
        }

        bool find = false;
        for(int j = i; j < s->size; j++) {
            if(s->array[j] == false) {
                printf("%d ", j);
                i = j;
                find = true;
                break;
            }
        }

        if(!find)
            break;
    }

    printf("\n");
}
