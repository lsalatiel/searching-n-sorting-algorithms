#include "item.h"
#include <stdlib.h>

void sort(Item *a, int lo, int hi) {
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
