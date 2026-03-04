#include <stdio.h>
#include <stdlib.h> // Required for the exit() function

#define MAX_SIZE 100 // Maximum size of the stack

int stack[MAX_SIZE];
int top = -1; // Indicates the stack is initially empty

/**
 * Function to push an element onto the stack.
 */
void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
    } else {
        top++;
        stack[top] = value;
    }
}

/**
 * Function to pop an element from the stack.
 */
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        int popped_value = stack[top];
        top--;
        printf("%d popped from the stack.\n", popped_value);
    }
}

/**
 * Function to display the elements of the stack.
 */
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are: ");
        // Iterate from the top to the bottom of the stack
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, operation_type, value;

    // Read the number of operations
    printf("Enter the number of operations (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for n.\n");
        return 1;
    }

    // Process n operations
    for (int i = 0; i < n; i++) {
        printf("\nEnter operation #%d (1: push, 2: pop, 3: display): ", i + 1);
        scanf("%d", &operation_type);

        switch (operation_type) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid operation type.\n");
        }
    }

    return 0;
}
