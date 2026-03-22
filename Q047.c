#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Function to find the height/max depth of a binary tree.
 * Logic: 1 + max(left_height, right_height)
 */
int getHeight(struct TreeNode* root) {
    // Base Case: If tree is empty, height is 0
    if (root == NULL) {
        return 0;
    }

    // Recursive calls for subtrees
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    // Return the taller subtree + 1 for the current node
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

// Helper function to create a node for testing in VS Code
struct TreeNode* createNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // Constructing a sample tree:
    //      1
    //     / \
    //    2   3
    //   /
    //  4
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    printf("Height of the tree: %d\n", getHeight(root)); // Output: 3

    return 0;
}
