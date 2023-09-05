#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    int n;

    scanf("%d", &n);

    BinaryTree *bt = binary_tree_construct();

    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        int key = rand() % 100;
        printf("%d\n", key);
        binary_tree_add(bt, key);
    }

    binary_tree_destroy(bt);

    return 0;
}
