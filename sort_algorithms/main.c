#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include <time.h>

// hi - the last index of the array
extern void sort(Item *a, int lo, int hi);

int main() {
    int n = 1000;

    // scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    clock_t time = clock();
    time = clock();

    sort(arr, 0, n - 1);

    time = clock() - time;
    double time_taken = ((double)time)/CLOCKS_PER_SEC;
    printf("%f\n", time_taken);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}
