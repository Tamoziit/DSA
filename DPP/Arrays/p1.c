#include <stdio.h>
#include <stdlib.h>
#define MAXROWS 100

int removeDups(int arr[], int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    // Variable to track the position of the unique elements
    int j = 0;

    for (int i = 0; i < n - 1; i++) {
        // If the current element is not equal to the next, it's unique
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }

    // Including the last element in the unique list
    arr[j++] = arr[n - 1];

    return j; // Returning the new length of the array
}

int main() {
    int i=0, n, ch;
    int *arr = (int*)malloc(MAXROWS * sizeof(int));
    printf("Enter elements. Press -1 to stop when prompted\n");
    while(1) {
        scanf("%d", &arr[i++]);
        printf("Continue?\n");
        scanf("%d", &ch);
        if(ch == -1)
            break;
    }

    n = i;
    printf("Original Array\n");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    n = removeDups(arr, n);
    printf("Array after removing Duplicates\n");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}