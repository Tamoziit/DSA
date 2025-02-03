#include <stdio.h>
#include <stdlib.h>

void displayArr(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void maxHeapify(int *arr, int i, int size)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max, t;

    // Compare left child with current node
    if (l < size && arr[l] > arr[i])
        max = l;
    else
        max = i;

    // Compare right child with max of current and left child
    if (r < size && arr[r] > arr[max])
        max = r;

    // If the current node is not the largest, swap with the largest child
    if (max != i)
    {
        t = arr[i];
        arr[i] = arr[max];
        arr[max] = t;
        maxHeapify(arr, max, size); // Heapify the affected subtree
    }
}

void buildMaxHeap(int *arr, int size)
{
    int i;
    // Start from the last non-leaf node and heapify down to the root
    for (i = size / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, i, size);
        printf("At node %d\n", i);
        displayArr(arr, size);
    }
}

int main()
{
    int n = 9;
    int arr[] = {2, 8, 6, 1, 10, 15, 3, 12, 11};
    buildMaxHeap(arr, n);

    printf("\nFinal Max Heap:\n");
    displayArr(arr, n);
    return 0;
}