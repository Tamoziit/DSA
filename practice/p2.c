#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct dnode
{
    int data;
    struct dnode *left;
    struct dnode *right;
} Dnode;

void insertAtBeginning(Dnode **h, Dnode **t, int val)
{
    Dnode *new = (Dnode *)malloc(sizeof(Dnode));
    if (new == NULL)
    {
        printf("Memory Alloc. Failed\n");
        exit(0);
    }
    new->data = val;

    if (*h == NULL && *t == NULL)
    {
        *h = new;
        *t = new;

        new->left = NULL;
        new->right = NULL;
    }
    else
    {
        new->right = *h;
        new->left = NULL;
        (*h)->left = new;
        *h = new;
    }
}

int deleteAtEnd(Dnode **h, Dnode **t)
{
    if (*h == NULL && *t == NULL)
    {
        printf("Empty List\n");
        return INT_MIN;
    }
    Dnode *tail, *head, *curr, *prev;
    int val;
    tail = *t;
    head = *h;
    curr = tail;
    val = curr->data;

    if (*h == *t)
    {
        *h = NULL;
        *t = NULL;
        free(curr);
        return val;
    }
    prev = curr->left;
    prev->right = NULL;
    tail = prev;
    free(curr);
    *t = tail;
    return val;
}

void printList(Dnode *h, Dnode *t, int index)
{
    if (index == 1)
    {
        Dnode *curr = h;
        printf("NULL");
        while (curr != NULL)
        {
            printf("<-%d->", curr->data);
            curr = curr->right;
        }
        printf("NULL\n");
    }
    else if (index == -1)
    {
        Dnode *curr = t;
        printf("NULL");
        while (curr != NULL)
        {
            printf("<-%d->", curr->data);
            curr = curr->left;
        }

        printf("NULL\n");
    }
    else
    {
        printf("Wrong Choice!\n");
    }
}

int main()
{
    Dnode *head = NULL, *tail = NULL;
    int ch, ele, val, pos;

    while (1)
    {
        printf("Enter\n 1. IAB\n 2. Del last node\n 3. Print List\n 9. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value\n");
            scanf("%d", &ele);
            insertAtBeginning(&head, &tail, ele);
            printList(head, tail, 1);
            break;
        case 2:
            val = deleteAtEnd(&head, &tail);
            if (val != INT_MIN)
            {
                printf("Deleted value = %d\n", val);
                printList(head, tail, 1);
            }
            break;
        case 3:
            printf("Enter 1 for left->right; -1 for right->left\n");
            scanf("%d", &val);
            printList(head, tail, val);
            break;
        case 9:
            printf("EOP\n");
            exit(0);
        default:
            printf("Wrong Choice\n");
        }
    }

    return 0;
}