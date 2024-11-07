#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack
{
    int data;
    struct stack *link;
} Stack;

Stack *insertAtBeginning(Stack *top, int val)
{
    Stack *new = (Stack *)malloc(sizeof(Stack));
    if (new != NULL)
    {
        new->data = val;
        new->link = top;
        top = new;
    }
    else
    {
        printf("Mem. Alloc. failed\n");
        exit(0);
    }
    return top;
}

int deleteAtBeginning(Stack **top)
{
    Stack *h = *top;
    if (h == NULL)
    {
        printf("Empty Stack\n");
        return INT_MIN;
    }
    else
    {

        Stack *temp = h;
        h = h->link;
        int v = temp->data;
        free(temp);
        *top = h;
        return v;
    }
}

void displayList(Stack *top)
{
    Stack *temp = top;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main()
{
    Stack *top = NULL;
    int val, ch;

    while (1)
    {
        printf("Enter:\n 1. Push\n 2. Pop\n 3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter ele\n");
            scanf("%d", &val);
            top = insertAtBeginning(top, val);
            displayList(top);
            break;
        case 2:
            val = deleteAtBeginning(&top);
            if (val != INT_MIN)
            {
                printf("Deleted Value = %d\n", val);
                displayList(top);
            }
            break;
        case 3:
            printf("End of Program\n");
            exit(0);
        default:
            printf("Wrong Choice!\n");
        }
    }

    return 0;
}