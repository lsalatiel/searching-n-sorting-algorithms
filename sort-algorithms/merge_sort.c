#include "item.h"
#include <stdlib.h>

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

void merge(Item *a, Item *aux, int lo, int mid, int hi) {
    for(int k = 0; k <= hi; k++)
        aux[k] = a[k]; // Copy array
    int i = lo, j = mid+1;
    for(int k = lo; k <= hi; k++) { // Merge
        if(i > mid) a[k] = aux[j++];
        else if(j > hi) a[k] = aux[i++];
        else if(less(aux[j], aux[i])) a[k] = aux[j++];
        else a[k] = aux[i++];
    }
}

void merge_sort(Item *a, Item *aux, int lo, int hi) {
    #ifdef CUTOFF
    if(hi <= lo + CUTOFF - 1) {
        insertion_sort(a, lo, hi);
        return;
    }
    #else
    if(hi <= lo) return;
    #endif
    int mid = lo + (hi - lo) / 2; // Avoid overflow
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    #ifdef MERGE_SKIP
    if(!less(a[mid+1], a[mid])) return;
    #endif
    merge(a, aux, lo, mid, hi);
}

void sort(Item *a, int lo, int hi) {
    int n = (hi - lo) + 1;
    Item *aux = malloc(n * sizeof(Item));
    merge_sort(a, aux, lo, hi);
    free(aux);
}
