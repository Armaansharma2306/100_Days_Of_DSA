#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Recursive Search Function
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key > root->data)
        return search(root->right, key);
    return search(root->left, key);
}
// ... (insert and main functions to build and test tree)
