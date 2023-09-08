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

    printf("pre-order traversal:\n");
    binary_tree_preorder_traversal(bt);

    printf("in-order traversal:\n");
    binary_tree_inorder_traversal(bt);

    printf("post-order traversal:\n");
    binary_tree_postorder_traversal(bt);

    return 0;
}
