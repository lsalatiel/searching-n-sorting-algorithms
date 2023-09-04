#include "item.h"
#include <stdlib.h>

void sort(Item *a, int lo, int hi) {
    int swapped = 1;
    int end = hi - 1;
    int start = lo;

    while(swapped) {
        swapped = 0;

        for(int i = start; i < end; i++) {
            if(less(a[i + 1], a[i])) {
                exch(a[i + 1], a[i]);
                swapped = 1;
            }
        }

        if(!swapped) break;

        swapped = 0;

        end--;

        for(int i = end - 1; i >= start; i--) {
            if(less(a[i + 1], a[i])) {
                exch(a[i + 1], a[i]);
                swapped = 1;
            }
        }

        start++;
    }
}
