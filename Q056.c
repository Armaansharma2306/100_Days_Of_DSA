#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Logic: Check if two subtrees are mirror images
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) 
        && isMirror(t1->left, t2->right) 
        && isMirror(t1->right, t2->left);
}

// Main logic function
bool isSymmetric(struct TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

int main() {
    // Manually building a symmetric tree: [1,2,2,3,4,4,3]
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root)) {
        printf("Tree is symmetric!\n");
    } else {
        printf("Tree is NOT symmetric.\n");
    }

    return 0;
}
