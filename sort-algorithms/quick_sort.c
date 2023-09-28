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

void quick_sort(Item *a, int lo, int hi) {
    if(hi <= lo) {
        return;
    } 
    
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j-1);
    quick_sort(a, j+1, hi);
}

void sort(Item *a, int lo, int hi) {
    shuffle(a, hi-lo+1);
    quick_sort(a, lo, hi);
}

