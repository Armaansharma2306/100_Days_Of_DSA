#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int queue[MAX];
int rear = -1;

// Function to check if the queue is empty
int isEmpty() { return rear == -1; }

// Function to check if the queue is full
int isFull() { return rear == MAX - 1; }

// Enqueue: Add element to end - O(1)
void enqueue(int element) {
    if (isFull()) return;
    queue[++rear] = element;
}

// Find index of min element - O(n)
int findMin() {
    int minIdx = 0;
    for (int i = 1; i <= rear; i++) {
        if (queue[i] < queue[minIdx]) minIdx = i;
    }
    return minIdx;
}

// Dequeue: Remove min element and shift - O(n)
int dequeue() {
    if (isEmpty()) return -1;
    int minIdx = findMin();
    int element = queue[minIdx];
    for (int i = minIdx; i < rear; i++) queue[i] = queue[i + 1];
    rear--;
    return element;
}

int main() {
    enqueue(10); enqueue(3); enqueue(20); enqueue(2);
    printf("Dequeued: %d\n", dequeue()); // 2
    printf("Dequeued: %d\n", dequeue()); // 3
    return 0;
}
