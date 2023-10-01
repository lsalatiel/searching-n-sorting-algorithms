#include <stdlib.h>
#include "item.h"
#include <sys/time.h>

int partition(Item *a, int lo, int hi) {
    int i = lo, j = hi + 1;
    Item v = a[lo];

    while(1) {
        while(less(a[++i], v)) { // find item on left to swap
            if(i == hi) break;
        }
        while(less(v, a[--j])) { // find item on right to swap
            if(j == lo) break;
        }

        if(i >= j) break; // check if pointers cross
        exch(a[i], a[j]);
    }

    exch(a[lo], a[j]); // swap with partitioning item
    return j; // return index of item now known to be in place
}

void shuffle(Item *a, int N) {
    struct timeval tv; gettimeofday(&tv, NULL);
    srand48(tv.tv_usec);
    for (int i = N-1; i > 0; i--) {
        int j = (unsigned int) (drand48()*(i+1));
        exch(a[i], a[j]);
    }
}

#ifdef CUTOFF
void insertion_sort(Item *a, int lo, int hi) {
    for (int i = hi; i > lo; i--)
        compexch(a[i-1], a[i]);

    for (int i = lo+2; i <= hi; i++) {
        int j = i;
        Item v = a[i];

        while (less(v, a[j-1])) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}
#endif

#ifdef MEDIAN_OF_3
int median_of_3(Item *a, int lo, int hi) {
    int mid = (lo + hi) / 2;
    
    if((a[lo] > a[mid]) ^ (a[lo] > a[hi])) // ^ -> bitwise XOR operator
        return lo;
    else if((a[mid] > a[lo]) ^ (a[mid] > a[hi]))
        return mid;
    else
        return hi;
}
#endif

void quick_sort(Item *a, int lo, int hi) {
    #ifdef CUTOFF
    if(hi <= lo + CUTOFF - 1) {
        insertion_sort(a, lo, hi);
        return;
    } 
    #else
    if(hi <= lo)
        return;
    #endif
    #ifdef MEDIAN_OF_3
    int median = median_of_3(a, lo, hi);
    exch(a[lo], a[median])
    #endif
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j-1);
    quick_sort(a, j+1, hi);
}


typedef struct {
   int *a;
   int size;
} Stack;

Stack *stack_init(int size) {
    Stack *stack = malloc(sizeof(Stack));
    stack->a = malloc(size * sizeof(int));
    stack->size = 0;

    return stack;
}

void stack_push(Stack *stack, int item) {
    stack->a[stack->size++] = item;
}

int stack_pop(Stack *stack) {
    return stack->a[--stack->size];
}

int stack_empty(Stack *stack) {
    return stack->size == 0;
}

void stack_destroy(Stack *stack) {
    free(stack->a);
    free(stack);
}

void quick_sort_iterative(Item *a, int lo, int hi) {
    Stack *s = stack_init(hi-lo+1);
    stack_push(s, hi); stack_push(s, lo);
    while(!stack_empty(s)) {
        lo = stack_pop(s); hi = stack_pop(s);
        #ifdef CUTOFF
        if(hi <= lo + CUTOFF - 1) {
            insertion_sort(a, lo, hi);
            return;
        } 
        #else
        if (hi <= lo) continue; // Could add cutoff here.
        #endif
        #ifdef MEDIAN_OF_3
        int median = median_of_3(a, lo, hi);
        exch(a[lo], a[median])
        #endif
        int i = partition(a, lo, hi);
        if (i-lo > hi-i) { // Test the size of sub-arrays.
            stack_push(s, i-1); stack_push(s, lo); // Push the larger one.
            stack_push(s, hi); stack_push(s, i+1); // Sort the smaller one first.
        } else {
            stack_push(s, hi); stack_push(s, i+1);
            stack_push(s, i-1); stack_push(s, lo);
        }
    }

    stack_destroy(s);
}

void sort(Item *a, int lo, int hi) {
    #ifdef ITERATIVE
    quick_sort_iterative(a, lo, hi);
    #else
    /* shuffle(a, hi-lo+1); */
    quick_sort(a, lo, hi);
    #endif
}

