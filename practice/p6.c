/* Queue using LL */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queueNode
{
    int data;
    struct queueNode *link;
} QL;

void enqueue(QL **front, QL **rear, int val)
{
    QL *new = (QL *)malloc(sizeof(QL));
    new->data = val;

    if (*front == NULL && *rear == NULL)
    {
        new->link = NULL;
        *front = new;
        *rear = new;
    }
    else
    {
        (*rear)->link = new;
        new->link = NULL;
        *rear = new;
    }
}

int dequeue(QL **front, QL **rear)
{
    if (*front == NULL && *rear == NULL)
    {
        printf("Underflow\n");
        return INT_MIN;
    }

    int val;
    QL *curr = *front;
    if (*front == *rear)
    {
        val = curr->data;
        *front = NULL;
        *rear = NULL;
        free(curr);
    }
    else
    {
        val = curr->data;
        *front = curr->link;
        free(curr);
    }

    return val;
}

void printQueue(QL *front, QL *rear)
{
    if (front == NULL && rear == NULL)
    {
        printf("Empty Queue\n");
        return;
    }

    QL *curr = front;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->link;
    }
    printf("\n");
}

int main()
{
    int ch, ele, val;
    QL *front = NULL, *rear = NULL;

    while (1)
    {
        printf("Enter\n 1. Enqueue\n 2. Dequeue\n 3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter val\n");
            scanf("%d", &ele);
            enqueue(&front, &rear, ele);
            printQueue(front, rear);
            break;
        case 2:
            val = dequeue(&front, &rear);
            if (val != INT_MIN)
            {
                printf("Deleted val = %d\n", val);
            }
            printQueue(front, rear);
            break;
        case 3:
            printf("EOP\n");
            exit(0);
        default:
            printf("Wrong Choice\n");
        }
    }
}