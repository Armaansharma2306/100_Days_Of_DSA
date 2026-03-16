#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node of the linked list
struct Node {
    int data;
    struct Node *next;
};

// Define pointers for the front and rear of the queue
struct Node *front = NULL;
struct Node *rear = NULL;

// Creates a new node dynamically
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Dynamically allocate memory
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Adds an element to the rear of the queue
void enqueue(int value) {
    struct Node* newNode = createNode(value);
    if (newNode == NULL) return;

    if (rear == NULL) {
        // If the queue is empty, the new node is both front and rear
        front = rear = newNode;
    } else {
        // Otherwise, link the new node at the end and update the rear pointer
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to the queue\n", value);
}

// Removes an element from the front of the queue
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty (underflow)!\n"); // Check for an empty queue
        return;
    }
    struct Node* temp = front; // Store the front node temporarily
    front = front->next; // Move the front pointer to the next node

    if (front == NULL) {
        rear = NULL; // If the queue becomes empty after dequeue, update rear to NULL
    }
    printf("Dequeued element: %d\n", temp->data);
    free(temp); // Free the memory of the removed node
}

// Displays all elements in the queue
void display() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    display(); // Output: Queue elements: 10 20
    dequeue();
    display(); // Output: Queue elements: 20
    return 0;
}
