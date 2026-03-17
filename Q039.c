#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX/INT_MIN if needed

#define MAX_SIZE 100

// Structure to represent a Min Heap
typedef struct MinHeap {
    int* arr;     // Array to store heap elements
    int size;     // Current number of elements in the heap
    int capacity; // Maximum capacity of the heap
} MinHeap;

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to get the index of the parent of a node at index i
int parent(int i) {
    return (i - 1) / 2;
}

// Function to get the index of the left child of a node at index i
int left_child(int i) {
    return (2 * i + 1);
}

// Function to get the index of the right child of a node at index i
int right_child(int i) {
    return (2 * i + 2);
}

// Function to create a Min Heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minheap = (MinHeap*)malloc(sizeof(MinHeap));
    minheap->arr = (int*)malloc(capacity * sizeof(int));
    minheap->capacity = capacity;
    minheap->size = 0;
    return minheap;
}

// Function to maintain the min-heap property from a given node downwards (Heapify Down)
void minHeapify(MinHeap* heap, int i) {
    int smallest = i;
    int left = left_child(i);
    int right = right_child(i);

    if (left < heap->size && heap->arr[left] < heap->arr[smallest]) {
        smallest = left;
    }

    if (right < heap->size && heap->arr[right] < heap->arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}

// Function to insert a new element into the Min Heap
void insert(MinHeap* heap, int element) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow\n");
        return;
    }

    // Insert the new element at the end
    int i = heap->size++;
    heap->arr[i] = element;

    // Fix the min-heap property by moving the element up (Heapify Up)
    while (i != 0 && heap->arr[parent(i)] > heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[parent(i)]);
        i = parent(i);
    }
}

// Function to extract the minimum element (root) from the Min Heap
int extractMin(MinHeap* heap) {
    if (heap->size <= 0) {
        return INT_MAX; // Return a sentinel value for empty heap
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    // Store the minimum value, and replace the root with the last element
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Heapify down from the root to restore the heap property
    minHeapify(heap, 0);

    return root;
}

// Function to display the elements in the heap array
void display(MinHeap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate the Min Heap operations
int main() {
    MinHeap* minheap = createMinHeap(MAX_SIZE);

    insert(minheap, 3);
    insert(minheap, 2);
    insert(minheap, 15);
    insert(minheap, 20);
    insert(minheap, 5);
    insert(minheap, 1);

    printf("Min Heap elements after insertions: ");
    display(minheap);

    printf("Extracted minimum element is: %d\n", extractMin(minheap));

    printf("Min Heap elements after extractMin: ");
    display(minheap);

    // Don't forget to free the allocated memory
    free(minheap->arr);
    free(minheap);

    return 0;
}
