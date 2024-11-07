#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue
{
    int data;
    struct queue *link;
} QL;

void enQueue(QL **front, QL **rear, int val)
{
    QL *new = (QL *)malloc(sizeof(QL));
    new->data = val;
    new->link = NULL;
    if (*front == NULL)
    {
        *front = new;
        *rear = new;
    }
    else
    {
        (*rear)->link = new;
        *rear = new;
    }
}

int deQueue(QL **front)
{
    QL *h = *front;
    int val;
    if (h == NULL)
    {
        printf("Empty Queue\n");
        return INT_MIN;
    }
    else
    {
        QL *temp = h;
        h = h->link;
        val = temp->data;
        free(temp);
        *front = h;
        return val;
    }
}

void printQueue(QL *front)
{
    QL *curr = front;
    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->link;
    }
    printf("\n");
}

int main()
{
    QL *front = NULL, *rear = NULL;
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
            enQueue(&front, &rear, ele);
            printQueue(front);
            break;
        case 2:
            val = deQueue(&front);
            if (val != INT_MIN)
            {
                printf("Deleted Value = %d\n", val);
            }
            printQueue(front);
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