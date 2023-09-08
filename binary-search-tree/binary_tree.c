#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

struct BinaryTree {
    Node *root;
};

Node *node_construct(int key, Node *left, Node *right) {
    Node *node = malloc(sizeof(Node));

    node->key = key;
    node->left = left;
    node->right = right;

    return node;
}

BinaryTree *binary_tree_construct() {
    BinaryTree *bt = malloc(sizeof(BinaryTree));
    bt->root = NULL;

    return bt;
}

void binary_tree_add(BinaryTree *bt, int key) {
    Node *node = node_construct(key, NULL, NULL);

    if(bt->root == NULL) {
        bt->root = node;
        return;
    }
    
    Node *current = bt->root;
    Node *prev = NULL;
    while(current != NULL) {
        prev = current;

        if(key == current->key)
            return;
        else if(key > current->key) 
            current = current->right;
        else
            current = current->left;
    }

    if(key > prev->key)
        prev->right = node;
    else
        prev->left = node;
}

void _binary_tree_destroy_recursive(Node *n) {
    if(n == NULL) return;

    _binary_tree_destroy_recursive(n->left);
    _binary_tree_destroy_recursive(n->right);

    free(n);
}

void binary_tree_destroy(BinaryTree *bt) {
    _binary_tree_destroy_recursive(bt->root);

    free(bt);
}

void _binary_tree_preorder_traversal_recursive(Node *n) {
    if(n == NULL) return;

    printf("%d ", n->key);
    _binary_tree_preorder_traversal_recursive(n->left);
    _binary_tree_preorder_traversal_recursive(n->right);
}

void binary_tree_preorder_traversal(BinaryTree *bt) {
    _binary_tree_preorder_traversal_recursive(bt->root);
}


