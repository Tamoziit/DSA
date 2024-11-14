/* Searching */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXROWS 100

typedef struct ele
{
    int val;
    int index;
} El;

int linearSearch(El *arr, int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i].val == key)
            return arr[i].index;
    }

    return INT_MIN;
}

int binSearch(El *arr, int n, int key)
{
    int mid, l = 0, h = n - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid].val == key)
            return arr[mid].index;
        else if (arr[mid].val > key)
            h = mid - 1;
        else if (arr[mid].val < key)
            l = mid + 1;
    }

    return INT_MIN;
}

int interpolationSearch(El *arr, int n, int key)
{
    int mid, l = 0, h = n - 1;
    while (l < h)
    {
        mid = ((key - arr[l].val) * (h - l)) / (arr[h].val - arr[l].val);
        if (arr[mid].val == key)
            return arr[mid].index;
        else if (arr[mid].val > key)
            h = mid - 1;
        else if (arr[mid].val < key)
            l = mid + 1;
    }

    return INT_MIN;
}

El *sort(El *arr, int n) {
    int i, j;
    El t;

    for(i=0; i<n-1; i++) {
        for(j=0; j<n-1-i; j++) {
            if(arr[j].val > arr[j+1].val)
            {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }

    return arr;
}

int main()
{
    int i = 0, j, key, ch, res;
    El *arr = (El *)malloc(MAXROWS * sizeof(El));
    printf("Enter the elements. Press -1 to stop\n");
    while (1)
    {
        scanf("%d", &arr[i].val);
        arr[i].index = i;
        i++;
        printf("Continue?\n");
        scanf("%d", &ch);
        if (ch == -1)
            break;
    }

    for (j = 0; j < i; j++)
    {
        printf("%d ", arr[j].val);
    }
    printf("\n");

    while (1)
    {
        printf("Enter\n 1. Linear Search\n 2. Binary Search\n 3. Interpolation Search\n 4. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to be searched\n");
            scanf("%d", &key);
            res = linearSearch(arr, i, key);
            if (res != INT_MIN)
                printf("Element found at position: %d\n", res + 1);
            else
                printf("Element not found\n");
            break;
        case 2:
            printf("Enter element to be searched\n");
            scanf("%d", &key);
            arr = sort(arr, i);
            res = binSearch(arr, i, key);
            if (res != INT_MIN)
                printf("Element found at position: %d\n", res + 1);
            else
                printf("Element not found\n");
            break;
        case 3:
            printf("Enter element to be searched\n");
            scanf("%d", &key);
            arr = sort(arr, i);
            res = interpolationSearch(arr, i, key);
            if (res != INT_MIN)
                printf("Element found at position: %d\n", res + 1);
            else
                printf("Element not found\n");
            break;
        case 4:
            printf("End of Program\n");
            free(arr);
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}