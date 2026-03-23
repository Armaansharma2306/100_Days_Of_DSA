#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node Structure
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 2. Helper to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 3. Your Implementation: Count Leaf Nodes
int countLeaves(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// 4. Main function to test in VS Code
int main() {
    /* Sample Tree:
            1
           / \
          2   3
         /     \
        4       5
    */
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->right = newNode(5);

    int result = countLeaves(root);
    printf("Total Leaf Nodes: %d\n", result); // Expected: 2 (nodes 4 and 5)

    return 0;
}
