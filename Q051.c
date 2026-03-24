#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node in BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

// Function to find LCA of two nodes
struct Node* findLCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        // If both p and q are smaller than root, LCA is in left subtree
        if (p < root->data && q < root->data)
            root = root->left;
        // If both p and q are larger than root, LCA is in right subtree
        else if (p > root->data && q > root->data)
            root = root->right;
        // If one is smaller and one is larger (or equal), this is the LCA
        else
            return root;
    }
    return NULL;
}

int main() {
    int n, val, p, q;
    struct Node* root = NULL;

    // Input N and the BST elements
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input the two node values
    scanf("%d %d", &p, &q);

    struct Node* lcaNode = findLCA(root, p, q);
    if (lcaNode != NULL)
        printf("%d\n", lcaNode->data);

    return 0;
}
