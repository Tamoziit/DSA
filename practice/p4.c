/* Stack using Array */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *push(int *arr, int *top, int val, int n)
{
    if (*top == n - 1)
    {
        printf("Overflow\n");
        return arr;
    }

    (*top)++;
    arr[*top] = val;
    return arr;
}

int pop(int *arr, int *top)
{
    if (*top == -1)
    {
        printf("Underflow\n");
        return INT_MIN;
    }

    int val = arr[*top];
    (*top)--;
    return val;
}

void printStack(int *arr, int *top)
{
    if (*top == -1)
    {
        printf("Empty Stack\n");
    }
    else
    {
        int i;
        for (i = (*top); i >= 0; i--)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n, ch, ele, val, top;
    printf("Enter n\n");
    scanf("%d", &n);
    int *stack = (int *)malloc(n * sizeof(int));
    top = -1;

    while (1)
    {
        printf("Enter\n 1. Push\n 2. Pop\n 3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter val\n");
            scanf("%d", &ele);
            stack = push(stack, &top, ele, n);
            printStack(stack, &top);
            break;
        case 2:
            val = pop(stack, &top);
            if (val != INT_MIN)
            {
                printf("Deleted val = %d\n", val);
            }
            printStack(stack, &top);
            break;
        case 3:
            printf("EOP\n");
            exit(0);
        default:
            printf("Wrong Choice\n");
        }
    }
}