#include <stdio.h>
#include <stdlib.h>

// Structure for a single node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Pointers to the front and rear of the queue
struct Node *front = NULL, *rear = NULL;

// Function prototypes
void enqueue(int value);
int dequeue();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue using Linked List Menu:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to add an element to the queue (enqueue)
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Dynamic allocation
    if (newNode == NULL) {
        printf("Memory allocation failed. Queue is full.\n");
        return;
    }
    newNode->data = value;
    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    rear->next = front; // Make it circular
    printf("%d enqueued to the queue.\n", value);
}

// Function to delete an element from the queue (dequeue)
int dequeue() {
    if (front == NULL) {
        printf("Queue is Empty. Dequeue not possible.\n");
        return -1; // Return -1 for error
    }
    struct Node* temp = front;
    int value = temp->data;

    if (front == rear) { // If only one element is present
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; // Maintain the circular link
    }
    free(temp); // Free the memory of the dequeued node
    return value;
}

// Function to display the elements of the queue
void display() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("Queue is Empty.\n");
        return;
    }
    printf("Elements in Circular Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}
