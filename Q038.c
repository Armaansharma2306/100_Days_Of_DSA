#include <stdio.h>
#define MAX 5 // Define the maximum size of the deque

int deque[MAX];
int front = -1, rear = -1;

// Function to check if the deque is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Function to check if the deque is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element at the front end
void insertFront(int x) {
    if (isFull()) {
        printf("Deque is full!\\n");
        return;
    }
    if (front == -1) { // If initially empty
        front = rear = 0;
    } else if (front == 0) { // Wrap around to the end
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = x;
}

// Function to insert an element at the rear end
void insertRear(int x) {
    if (isFull()) {
        printf("Deque is full!\\n");
        return;
    }
    if (front == -1) { // If initially empty
        front = rear = 0;
    } else if (rear == MAX - 1) { // Wrap around to the beginning
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

// Function to delete an element from the front end
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty!\\n");
        return;
    }
    printf("Deleted element: %d\\n", deque[front]);
    if (front == rear) { // If only one element was present
        front = rear = -1;
    } else if (front == MAX - 1) { // Wrap around to the beginning
        front = 0;
    } else {
        front++;
    }
}

// Function to delete an element from the rear end
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty!\\n");
        return;
    }
    printf("Deleted element: %d\\n", deque[rear]);
    if (front == rear) { // If only one element was present
        front = rear = -1;
    } else if (rear == 0) { // Wrap around to the end
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Function to display elements in the deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty!\\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\\n");
}

// Main function to demonstrate operations
int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display(); // Output: 5 10 20

    deleteFront(); // Deleted element: 5
    display();     // Output: 10 20

    insertFront(3);
    insertRear(40);
    display(); // Output: 3 10 20 40
    
    deleteRear(); // Deleted element: 40
    display(); // Output: 3 10 20

    return 0;
}
