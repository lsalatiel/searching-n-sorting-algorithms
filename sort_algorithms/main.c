#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include <time.h>

extern void sort(Item *a, int lo, int hi);

int main() {
    int n;

    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    clock_t time = clock();
    time = clock();

    sort(arr, 0, n);

    time = clock() - time;
    double time_taken = ((double)time)/CLOCKS_PER_SEC;

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}
