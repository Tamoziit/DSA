#include <stdio.h>
#include <stdlib.h>
#define MAXROWS 100

void reverse(int arr[], int n)
{
    int i, t;
    for (i = 0; i < n / 2; i++)
    {
        t = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = t;
    }
}

int main()
{
    int i = 0, n, ch;
    int *arr = (int *)malloc(MAXROWS * sizeof(int));
    printf("Enter elements. Press -1 to stop when prompted\n");
    while (1)
    {
        scanf("%d", &arr[i++]);
        printf("Continue?\n");
        scanf("%d", &ch);
        if (ch == -1)
            break;
    }

    n = i;
    printf("Original Array\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    reverse(arr, n);
    printf("Reversed Array\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}