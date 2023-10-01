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

void sort(Item *a, int lo, int hi) {
    shuffle(a, hi-lo+1);
    quick_sort(a, lo, hi);
}

