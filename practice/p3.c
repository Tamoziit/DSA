/* Queue using Array */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *enqueue(int *arr, int n, int val, int *front, int *rear)
{
    if (*rear == n - 1)
    {
        printf("Overflow\n");
        return arr;
    }

    if (*front == -1)
    {
        (*front)++;
        (*rear)++;
        arr[*rear] = val;
    }
    else
    {
        (*rear)++;
        arr[*rear] = val;
    }

    return arr;
}

int dequeue(int **arr1, int *front, int *rear)
{
    int *arr = *arr1;

    if (*rear == -1 && *front == -1)
    {
        printf("Underflow\n");
        return INT_MIN;
    }

    int val;
    if (*front == 0 && *rear == 0)
    {
        val = arr[(*front)];
        (*front)--;
        (*rear)--;
    }
    else
    {
        val = arr[(*front)];
        int i;
        for (i = (*front); i < (*rear); i++)
        {
            arr[i] = arr[i + 1];
        }
        (*rear)--;
    }
    *arr1 = arr;
    return val;
}

void printQueue(int *arr, int *front, int *rear)
{
    if (*front == -1 && *rear == -1)
    {
        printf("Empty Queue\n");
        return;
    }

    int i;
    for (i = (*front); i <= (*rear); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n, ch, ele, val, front, rear;
    printf("Enter n\n");
    scanf("%d", &n);
    int *queue = (int *)malloc(n * sizeof(int));
    front = -1, rear = -1;

    while (1)
    {
        printf("Enter\n 1. Enqueue\n 2. Dequeue\n 3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter val\n");
            scanf("%d", &ele);
            queue = enqueue(queue, n, ele, &front, &rear);
            printQueue(queue, &front, &rear);
            break;
        case 2:
            val = dequeue(&queue, &front, &rear);
            if (val != INT_MIN)
            {
                printf("Deleted val = %d\n", val);
            }
            printQueue(queue, &front, &rear);
            break;
        case 3:
            printf("EOP\n");
            exit(0);
        default:
            printf("Wrong Choice\n");
        }
    }
}