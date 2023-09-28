#include <stdlib.h>
#include "item.h"

void sort(Item *a, int lo, int hi) {
    int h = 1;
    while (h < (hi-lo)/9) { // 3x+1 increment sequence
        h = 3*h + 1;
    }
    while (h > 0) { // h-sort the array.
        for (int i = lo+h; i <= hi; i++) {
            int j = i; // insertion sort
            Item v = a[i];
            while (j >= lo+h && less(v, a[j-h])) {
                a[j] = a[j-h];
                j -= h;
            }
            a[j] = v;
        }
        h /= 3; // move to next increment
    }
}
