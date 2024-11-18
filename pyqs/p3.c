#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n)
{
    int bound = n - 1, t, j;
    do
    {
        t = 0;
        for (j = 0; j < bound; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                t = j;
            }
        }
        bound = t;
    } while (bound > 0);
}

void insertionSort(int *arr, int n)
{
    int i, j, k;
    for (i = 1; i < n; i++)
    {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}

void printArr(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n, *arr1, *arr2, i, val;
    printf("Enter n\n");
    scanf("%d", &n);
    arr1 = (int *)malloc(n * sizeof(int));
    arr2 = (int *)malloc(n * sizeof(int));

    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        arr1[i] = val;
        arr2[i] = val;
    }

    printf("Initially the array:\n");
    printArr(arr1, n);

    bubbleSort(arr1, n);
    printf("After Bubble sorting, the array:\n");
    printArr(arr1, n);

    insertionSort(arr2, n);
    printf("After Insertion sorting, the array:\n");
    printArr(arr2, n);

    return 0;
}