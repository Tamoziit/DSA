/* Queue using Circular LL */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct circQueue {
    int data;
    struct circQueue *link;
} CL;

void enqueue(CL **tail_rear, int val) {
    CL *new = (CL*)malloc(sizeof(CL));
    if(new == NULL) {
        printf("Memory Alloc. Failed\n");
        exit(0);
    }

    new->data = val;
    if(*tail_rear == NULL) {
        *tail_rear = new;
        new->link = new;
    } else {
        new->link = (*tail_rear)->link;
        (*tail_rear)->link = new;
        *tail_rear = new;
    }
}

int dequeue(CL **tail_rear) {
    if(*tail_rear == NULL) {
        printf("Underflow\n");
        return INT_MIN;
    }

    int val;
    CL *curr = (*tail_rear)->link;
    if(curr == *tail_rear)
    {
        val = curr->data;
        free(curr);
        *tail_rear = NULL;
    } else {
        val = curr->data;
        (*tail_rear)->link = curr->link;
        free(curr);
    }

    return val;
}

void printQueue(CL *tail_rear) {
    if(tail_rear == NULL) {
        printf("Empty Queue\n");
        return;
    }

    CL *curr = tail_rear->link;
    while(curr != tail_rear) {
        printf("%d ", curr->data);
        curr = curr->link;
    }
    printf("%d \n", curr->data);
}

int main()
{
    int ch, ele, val;
    CL *tail_rear = NULL;

    while (1)
    {
        printf("Enter\n 1. Enqueue\n 2. Dequeue\n 3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter val\n");
            scanf("%d", &ele);
            enqueue(&tail_rear, ele);
            printQueue(tail_rear);
            break;
        case 2:
            val = dequeue(&tail_rear);
            if (val != INT_MIN)
            {
                printf("Deleted val = %d\n", val);
            }
            printQueue(tail_rear);
            break;
        case 3:
            printf("EOP\n");
            exit(0);
        default:
            printf("Wrong Choice\n");
        }
    }
}