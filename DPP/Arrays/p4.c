#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a heap node
typedef struct {
    int value;
    int queueIndex;
} HeapNode;

// Function prototypes
void heapify(HeapNode heap[], int size, int index);
void insertHeap(HeapNode heap[], int *heapSize, int value, int queueIndex);
HeapNode extractMin(HeapNode heap[], int *heapSize);
int isDuplicate(int value, int lastAdded);

// Merge function
void mergeSortedQueues(int queues[][100], int sizes[], int numQueues, int result[], int *resultSize) {
    HeapNode heap[8];  // Min-heap to hold the smallest elements from each queue
    int heapSize = 0;
    int queuePointers[8] = {0};  // Tracks the current position in each queue
    int lastAdded = INT_MIN;  // To track duplicates

    // Initialize the heap with the first element of each queue
    for (int i = 0; i < numQueues; i++) {
        if (sizes[i] > 0) {  // If the queue is not empty
            insertHeap(heap, &heapSize, queues[i][0], i);
            queuePointers[i] = 1;  // Move the pointer to the next element
        }
    }

    *resultSize = 0;

    // Process the heap until it is empty
    while (heapSize > 0) {
        HeapNode minNode = extractMin(heap, &heapSize);

        // Check for duplicates
        if (!isDuplicate(minNode.value, lastAdded)) {
            result[(*resultSize)++] = minNode.value;
            lastAdded = minNode.value;
        }

        // Add the next element from the same queue to the heap
        int queueIndex = minNode.queueIndex;
        if (queuePointers[queueIndex] < sizes[queueIndex]) {
            int nextValue = queues[queueIndex][queuePointers[queueIndex]++];
            insertHeap(heap, &heapSize, nextValue, queueIndex);
        }
    }
}

// Helper function to maintain the min-heap property
void heapify(HeapNode heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left].value < heap[smallest].value) {
        smallest = left;
    }
    if (right < size && heap[right].value < heap[smallest].value) {
        smallest = right;
    }

    if (smallest != index) {
        HeapNode temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;

        heapify(heap, size, smallest);
    }
}

// Insert a new element into the heap
void insertHeap(HeapNode heap[], int *heapSize, int value, int queueIndex) {
    int index = (*heapSize)++;
    heap[index].value = value;
    heap[index].queueIndex = queueIndex;

    while (index != 0 && heap[(index - 1) / 2].value > heap[index].value) {
        HeapNode temp = heap[index];
        heap[index] = heap[(index - 1) / 2];
        heap[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

// Extract the smallest element from the heap
HeapNode extractMin(HeapNode heap[], int *heapSize) {
    HeapNode minNode = heap[0];
    heap[0] = heap[--(*heapSize)];
    heapify(heap, *heapSize, 0);
    return minNode;
}

// Check if a value is a duplicate
int isDuplicate(int value, int lastAdded) {
    return value == lastAdded;
}

// Main function to test the code
int main() {
    int queues[8][100] = {
        {1, 4, 7},
        {2, 3, 6},
        {3, 5, 8},
        {0, 9},
        {10},
        {4, 6},
        {8, 11, 12},
        {0, 13}
    };

    int sizes[8] = {3, 3, 3, 2, 1, 2, 3, 2};  // Sizes of each queue
    int result[100];  // Resultant merged queue
    int resultSize;

    // Merge the sorted queues
    mergeSortedQueues(queues, sizes, 8, result, &resultSize);

    // Print the result
    printf("Merged Queue (sorted, duplicates removed):\n");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}