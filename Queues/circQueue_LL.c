#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct circQueue
{
    int data;
    struct circQueue *link;
} CQ;

CQ *enQueue(CQ *tail_rear, int val)
{
    CQ *new = (CQ *)malloc(sizeof(CQ));
    if (new == NULL)
    {
        printf("Memory Alloc. Failed\n");
        exit(0);
    }

    new->data = val;
    if (tail_rear == NULL)
    {
        tail_rear = new;
        new->link = new;
    }
    else
    {
        new->link = tail_rear->link;
        tail_rear->link = new;
        tail_rear = new;
    }
}

int deQueue(CQ **tail_rear)
{
    if (*tail_rear == NULL)
    {
        printf("Underflow\n");
        return INT_MIN;
    }

    int val;
    CQ *curr = (*tail_rear)->link;
    if (curr == *tail_rear)
    {
        *tail_rear = NULL;
        val = curr->data;
        free(curr);
    }
    else
    {
        (*tail_rear)->link = curr->link;
        val = curr->data;
        free(curr);
    }

    return val;
}

void printQueue(CQ *tail_rear)
{
    CQ *curr;

    if (tail_rear != NULL)
    {
        curr = tail_rear->link;
        while (curr->link != tail_rear->link)
        {
            printf("%d ", curr->data);
            curr = curr->link;
        }
        printf("%d ", curr->data);
        printf("\n");
    }
    else
    {
        printf("Empty Queue\n");
    }
}

int main()
{
    CQ *tail_rear;
    int ch, val, ele;

    while (1)
    {
        printf("Enter\n 1. EnQueue\n 2. DeQueue\n 3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value\n");
            scanf("%d", &ele);
            tail_rear = enQueue(tail_rear, ele);
            printQueue(tail_rear);
            break;
        case 2:
            val = deQueue(&tail_rear);
            if (val != INT_MIN)
            {
                printf("Deleted Value = %d\n", val);
            }
            printQueue(tail_rear);
            break;
        case 3:
            printf("EOP\n");
            exit(0);
        default:
            printf("Wrong Choice!\n");
        }
    }

    return 0;
}