/* Stack using LL */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stackNode
{
    int data;
    struct stackNode *link;
} SL;

SL *push(SL *top, int val)
{
    SL *new = (SL *)malloc(sizeof(SL));
    new->data = val;

    if (top == NULL)
    {
        top = new;
        new->link = NULL;
        return top;
    }

    new->link = top;
    top = new;
    return top;
}

int pop(SL **top)
{
    if (*top == NULL)
    {
        printf("Underflow\n");
        return INT_MIN;
    }

    SL *curr = *top;
    int val;
    if (curr->link == NULL)
    {
        val = curr->data;
        *top = NULL;
        free(curr);
    }
    else
    {
        val = curr->data;
        *top = curr->link;
        free(curr);
    }

    return val;
}

void printStack(SL *top)
{
    if (top == NULL)
    {
        printf("Empty Stack\n");
        return;
    }

    SL *curr = top;
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
    SL *top = NULL;

    while (1)
    {
        printf("Enter\n 1. Push\n 2. Pop\n 3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter val\n");
            scanf("%d", &ele);
            top = push(top, ele);
            printStack(top);
            break;
        case 2:
            val = pop(&top);
            if (val != INT_MIN)
            {
                printf("Deleted val = %d\n", val);
            }
            printStack(top);
            break;
        case 3:
            printf("EOP\n");
            exit(0);
        default:
            printf("Wrong Choice\n");
        }
    }
}