#include <stdio.h>
#include <stdlib.h>
#define MAXROWS 100

typedef struct arr
{
    int val;
    int idx;
} Arr;

int binSearch(Arr *arr, int n, int key)
{
    int l = 0, h = n - 1;
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid].val > key)
            return arr[mid].idx;
        else if (arr[mid].val > key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

Arr *sort(Arr *arr, int n)
{
    int i, j;
    Arr t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j].val > arr[j + 1].val)
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
    return arr;
}

int main()
{
    int i = 0, j, key, ch, res;
    Arr *arr = (Arr *)malloc(MAXROWS * sizeof(Arr));
    printf("Enter the elements. Press -1 to stop\n");
    while (1)
    {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
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

    printf("Enter element to be searched\n");
    scanf("%d", &key);

    arr = sort(arr, i);
    res = binSearch(arr, i, key);
    if (res != -1)
        printf("Element found at position: %d\n", res + 1);
    else
        printf("Element not found\n");

    return 0;
}