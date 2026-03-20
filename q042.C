#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// --- Stack Implementation (LIFO) ---
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack* s) {
    s->top = -1;
}

int is_empty_stack(Stack* s) {
    return s->top == -1;
}

int is_full_stack(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, int item) {
    if (is_full_stack(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = item;
}

int pop(Stack* s) {
    if (is_empty_stack(s)) {
        printf("Stack Underflow\n");
        return -1; // Or handle error appropriately
    }
    return s->arr[s->top--];
}

// --- Queue Implementation (FIFO) ---
typedef struct {
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

void init_queue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty_queue(Queue* q) {
    return q->front == -1;
}

int is_full_queue(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue* q, int item) {
    if (is_full_queue(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (is_empty_queue(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->arr[q->rear] = item;
}

int dequeue(Queue* q) {
    if (is_empty_queue(q)) {
        printf("Queue Underflow\n");
        return -1; // Or handle error appropriately
    }
    int item = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return item;
}

void display_queue(Queue* q) {
    if (is_empty_queue(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", q->arr[q->rear]);
}

// --- Function to reverse the queue using a stack ---
void reverse_queue(Queue* q) {
    Stack s;
    init_stack(&s);

    // 1. Dequeue all elements from the queue and push onto the stack.
    while (!is_empty_queue(q)) {
        push(&s, dequeue(q));
    }

    // 2. Pop all elements from the stack and enqueue them back into the queue.
    while (!is_empty_stack(&s)) {
        enqueue(q, pop(&s));
    }
}

// --- Main function for demonstration ---
int main() {
    Queue q;
    init_queue(&q);

    // Enqueue some elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Original Queue: ");
    display_queue(&q);

    // Reverse the queue
    reverse_queue(&q);

    printf("Reversed Queue: ");
    display_queue(&q);

    return 0;
}
