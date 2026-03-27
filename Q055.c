#include <stdio.h>
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
    node->left = NULL;
    node->right = NULL;
    return node;
}

// DFS to find the right side view
void dfs(struct TreeNode* root, int level, int* res, int* returnSize) {
    if (root == NULL) return;

    // If level matches result size, this is the first (rightmost) node seen at this depth
    if (level == *returnSize) {
        res[(*returnSize)++] = root->val;
    }

    // Traverse RIGHT first
    dfs(root->right, level + 1, res, returnSize);
    dfs(root->left, level + 1, res, returnSize);
}

int main() {
    // Constructing a sample tree:
    //      1
    //     / \
    //    2   3
    //     \   \
    //      5   4
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(4);

    int returnSize = 0;
    int res[100]; // Array to store visible nodes

    dfs(root, 0, res, &returnSize);

    printf("Right Side View: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
