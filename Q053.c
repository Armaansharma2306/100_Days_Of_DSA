
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Queue element to store node and its horizontal distance
struct QueueNode {
    struct Node* node;
    int hd;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Helper to find min/max HD to determine the range of vertical lines
void findMinMax(struct Node* node, int* min, int* max, int hd) {
    if (node == NULL) return;
    if (hd < *min) *min = hd;
    else if (hd > *max) *max = hd;
    findMinMax(node->left, min, max, hd - 1);
    findMinMax(node->right, min, max, hd + 1);
}

// Print nodes for a specific vertical line (hd) using level-order
void printVerticalLine(struct Node* root, int line_no, int hd) {
    if (root == NULL) return;
    
    // Using a manual queue for Level Order Traversal
    struct QueueNode queue[100];
    int head = 0, tail = 0;
    queue[tail++] = (struct QueueNode){root, 0};

    while (head < tail) {
        struct QueueNode temp = queue[head++];
        if (temp.hd == line_no) printf("%d ", temp.node->data);
        
        if (temp.node->left) queue[tail++] = (struct QueueNode){temp.node->left, temp.hd - 1};
        if (temp.node->right) queue[tail++] = (struct QueueNode){temp.node->right, temp.hd + 1};
    }
}

void verticalOrder(struct Node* root) {
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    for (int line_no = min; line_no <= max; line_no++) {
        printVerticalLine(root, line_no, 0);
        printf("\n");
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);
    return 0;
}
