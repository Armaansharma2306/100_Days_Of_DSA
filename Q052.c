#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find LCA of n1 and n2
struct Node* findLCA(struct Node* root, int n1, int n2) {
    // Base case: if root is null
    if (root == NULL) return NULL;

    // If either n1 or n2 matches the root, the root is the LCA 
    // (covers cases where one node is an ancestor of the other)
    if (root->data == n1 || root->data == n2) return root;

    // Look for keys in left and right subtrees
    struct Node* left_lca = findLCA(root->left, n1, n2);
    struct Node* right_lca = findLCA(root->right, n1, n2);

    // If both calls return non-NULL, one key is in the left subtree 
    // and the other is in the right, so this node is the LCA
    if (left_lca && right_lca) return root;

    // Otherwise return the non-NULL child
    return (left_lca != NULL) ? left_lca : right_lca;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int n1 = 4, n2 = 5;
    struct Node* t = findLCA(root, n1, n2);
    if (t != NULL)
        printf("LCA of %d and %d is %d\n", n1, n2, t->data);
    else
        printf("Keys are not present\n");

    return 0;
}
