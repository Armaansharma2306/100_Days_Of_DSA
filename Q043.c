#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Define the structure for a queue node (used internally by the queue)
struct QNode {
    struct TreeNode *treeNode;
    struct QNode *next;
};

// Define the structure for the Queue
struct Queue {
    struct QNode *front;
    struct QNode *rear;
};

// Function to create a new tree node
struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new queue node
struct QNode* createQNode(struct TreeNode* treeNode) {
    struct QNode* newNode = (struct QNode*)malloc(sizeof(struct QNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to enqueue a tree node into the queue
void enqueue(struct Queue* q, struct TreeNode* treeNode) {
    struct QNode* newNode = createQNode(treeNode);
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue a tree node from the queue
struct TreeNode* dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    struct QNode* temp = q->front;
    struct TreeNode* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return treeNode;
}

// Function to construct the binary tree from a level-order array
struct TreeNode* constructTreefromLevelOrder(int arr[], int n) {
    if (n <= 0) {
        return NULL;
    }

    struct TreeNode* root = createTreeNode(arr[0]);
    struct Queue q;
    q.front = q.rear = NULL;
    enqueue(&q, root);

    int i = 1;
    while (i < n && !isEmpty(&q)) {
        struct TreeNode* current = dequeue(&q);

        // Add left child
        if (i < n) {
            current->left = createTreeNode(arr[i++]);
            enqueue(&q, current->left);
        }

        // Add right child
        if (i < n) {
            current->right = createTreeNode(arr[i++]);
            enqueue(&q, current->right);
        }
    }
    return root;
}

// Helper function to print the tree in-order to verify construction
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    // Example level-order traversal: 1 2 3 4 5 6 7
    int levelOrder[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(levelOrder) / sizeof(levelOrder[0]);

    // Construct the tree
    struct TreeNode* root = constructTreefromLevelOrder(levelOrder, n);

    // Verify the construction using in-order traversal
    printf("In-order traversal of the constructed tree: ");
    inorderTraversal(root);
    printf("\n");

    // Free allocated memory (omitted for brevity, but important for real applications)
    return 0;
}
