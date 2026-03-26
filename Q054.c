#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Stack structure for tree nodes
struct Stack {
    int top;
    int capacity;
    struct Node** array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct Node**)malloc(stack->capacity * sizeof(struct Node*));
    return stack;
}

void push(struct Stack* stack, struct Node* node) {
    stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Zigzag Traversal using two stacks
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    // Stack1 for Left-to-Right levels, Stack2 for Right-to-Left
    struct Stack* s1 = createStack(100); 
    struct Stack* s2 = createStack(100);

    push(s1, root);

    while (!isEmpty(s1) || !isEmpty(s2)) {
        // Process current level: Left to Right
        while (!isEmpty(s1)) {
            struct Node* temp = pop(s1);
            printf("%d ", temp->data);

            // Push children to s2: Left then Right
            if (temp->left) push(s2, temp->left);
            if (temp->right) push(s2, temp->right);
        }
        printf("\n");

        // Process next level: Right to Left
        while (!isEmpty(s2)) {
            struct Node* temp = pop(s2);
            printf("%d ", temp->data);

            // Push children to s1: Right then Left
            if (temp->right) push(s1, temp->right);
            if (temp->left) push(s1, temp->left);
        }
        printf("\n");
    }
}

// Helper to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);

    printf("Zigzag Order Traversal:\n");
    zigzagTraversal(root);

    return 0;
}
