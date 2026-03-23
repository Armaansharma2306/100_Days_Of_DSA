#include <stdio.h>
#include <stdlib.h>

// 1. Define the BST Node structure
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 2. Helper to create a new node (allocates memory)
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 3. Your Implementation: Insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    // If we reach a NULL position, this is where the new node goes
    if (root == NULL) {
        return createNode(val);
    }

    // Traverse: smaller values left, larger values right
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// 4. Helper: In-order traversal to verify the BST (should be sorted)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// 5. Main function to test in VS Code
int main() {
    struct TreeNode* root = NULL;

    // Example: Insert values [4, 2, 7, 1, 3]
    root = insertIntoBST(root, 4);
    insertIntoBST(root, 2);
    insertIntoBST(root, 7);
    insertIntoBST(root, 1);
    insertIntoBST(root, 3);

    printf("In-order Traversal (should be sorted): ");
    inorder(root);
    printf("\n");

    return 0;
}
