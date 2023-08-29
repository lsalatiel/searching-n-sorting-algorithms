#include "item.h"
#include <stdlib.h>

void sort(Item *a, int lo, int hi) {
    for(int i = lo; i < hi - 1; i++) {
        if(less(a[i + 1], a[i])) 
            exch(a[i + 1], a[i])
        else {
            for(int j = i; j > 0; j--) {
                if(less(a[j], a[j - 1]))
                    exch(a[j], a[j - 1])
            }
        }
    }
}
