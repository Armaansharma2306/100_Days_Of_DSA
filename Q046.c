#include <stdio.h>
#include <stdlib.h>

// 1. DEFINE the struct only once at the top
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 2. Implementation of Level Order Traversal
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    int** result = (int**)malloc(2000 * sizeof(int*)); 
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    struct TreeNode** queue = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;
        (*returnColumnSizes)[*returnSize] = levelSize;
        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            result[*returnSize][i] = node->val;
            if (node->left)  queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }
        (*returnSize)++;
    }
    free(queue);
    return result;
}

// 3. Main function to test your code
int main() {
    // Logic to build a small tree and call levelOrder here
    printf("Program compiled successfully!\n");
    return 0;
}
