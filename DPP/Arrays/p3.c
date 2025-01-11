#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Insert at Rear
void insertAtRear(int ele, int arr[], int size, int *front, int *rear) {
    if ((*rear + 1) % size == *front) { // Deque full
        printf("Deque is full\n");
        return;
    }

    if (*front == -1) { // Empty deque
        *front = 0;
        *rear = 0;
    } else {
        *rear = (*rear + 1) % size; // Move rear circularly
    }

    arr[*rear] = ele;
}

// Delete from Front
int deleteFront(int arr[], int size, int *front, int *rear) {
    int val;
    if (*front == -1) { // Deque is empty
        printf("Deque is empty\n");
        return INT_MIN;
    }

    val = arr[*front];

    if (*front == *rear) { // Only one element left
        *front = -1;
        *rear = -1;
    } else {
        *front = (*front + 1) % size; // Move front circularly
    }

    return val;
}

// Delete from Rear
int deleteRear(int arr[], int size, int *front, int *rear) {
    int val;
    if (*rear == -1) { // Deque is empty
        printf("Deque is empty\n");
        return INT_MIN;
    }

    val = arr[*rear];

    if (*front == *rear) { // Only one element left
        *front = -1;
        *rear = -1;
    } else {
        *rear = (*rear - 1 + size) % size; // Move rear circularly backward
    }

    return val;
}

// Print the Deque
void printDeque(int arr[], int size, int front, int rear) {
    if (front == -1) { // Deque is empty
        printf("Empty Deque\n");
        return;
    }

    printf("The Deque:\n");
    int i = front;
    while (1) {
        printf("%d ", arr[i]);
        if (i == rear)
            break;
        i = (i + 1) % size; // Move circularly
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter max size:\n");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    int front = -1, rear = -1;
    int ele, val, ch;

    while (1) {
        printf("Enter:\n 1. Insert from rear\n 2. Delete from front\n 3. Delete from rear\n 4. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter element:\n");
            scanf("%d", &ele);
            insertAtRear(ele, arr, size, &front, &rear);
            printDeque(arr, size, front, rear);
            break;
        case 2:
            val = deleteFront(arr, size, &front, &rear);
            if (val != INT_MIN) {
                printf("Deleted Value = %d\n", val);
            }
            printDeque(arr, size, front, rear);
            break;
        case 3:
            val = deleteRear(arr, size, &front, &rear);
            if (val != INT_MIN) {
                printf("Deleted Value = %d\n", val);
            }
            printDeque(arr, size, front, rear);
            break;
        case 4:
            printf("End of Program\n");
            free(arr);
            exit(0);
        default:
            printf("Wrong Choice!\n");
        }
    }

    return 0;
}