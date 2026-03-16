#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Define a structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Global pointer to the top of the stack
Node* top = NULL;

/**
 * Creates a new node and allocates memory dynamically.
 */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Dynamic memory allocation
    if (newNode == NULL) {
        printf("Memory allocation failed (Stack Overflow)!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * Pushes an element onto the stack.
 */
void push(int data) {
    Node* newNode = createNode(data);
    newNode->next = top;
    top = newNode;
}

/**
 * Pops an element from the stack and returns its value.
 */
int pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    Node* temp = top;
    int poppedData = temp->data;
    top = top->next;
    free(temp); // Free the memory of the popped node
    return poppedData;
}

/**
 * Checks if a character is an operator.
 */
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

/**
 * Performs the arithmetic operation.
 */
int performOperation(int op1, int op2, char op) {
    switch (op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2; // Order matters for subtraction/division
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return (int)pow(op1, op2); // For exponentiation
    }
    return 0;
}

/**
 * Evaluates the postfix expression.
 * Assumes space-separated tokens for multi-digit support.
 */
int evaluatePostfix(char* exp) {
    char *token;
    // Use strtok to handle space-separated operands/operators
    token = strtok(exp, " \n");

    while (token != NULL) {
        if (isdigit(token[0]) || (strlen(token) > 1 && isdigit(token[1]))) {
            // It's an operand, convert to int and push to stack
            push(atoi(token));
        } else if (isOperator(token[0]) && strlen(token) == 1) {
            // It's an operator, pop two operands, operate, and push result
            int val2 = pop(); // Second operand is popped first
            int val1 = pop(); // First operand is popped second
            int result = performOperation(val1, val2, token[0]);
            push(result);
        }
        // Move to the next token
        token = strtok(NULL, " \n");
    }

    // The final result is the only element left on the stack
    return pop();
}

int main() {
    char exp[100];
    printf("Enter postfix expression (space separated, e.g., \"2 3 1 * + 9 -\"): ");
    fgets(exp, 100, stdin); // Read the expression including spaces

    int result = evaluatePostfix(exp);
    printf("The result is: %d\n", result);

    return 0;
}
