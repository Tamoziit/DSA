#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct dnode
{
    int data;
    struct dnode *left;
    struct dnode *right;
} Dnode;

void insertAtEnd(Dnode **hptr, Dnode **tptr, int val)
{
    Dnode *new = (Dnode *)malloc(sizeof(Dnode));
    new->data = val;
    new->right = NULL;
    new->left = *tptr;

    if (*tptr != NULL)
        (*tptr)->right = new;
    *tptr = new;

    if (*hptr == NULL)
        *hptr = new;
}

void insertAfterTarget(Dnode **hptr, Dnode **tptr, int target, int val)
{
    Dnode *curr = *hptr;
    int flag = 0;
    if (*hptr == NULL)
    {
        printf("Empty List\n");
        return;
    }

    while (curr != NULL)
    {
        if (curr->data == target)
        {
            Dnode *new = (Dnode *)malloc(sizeof(Dnode));
            new->data = val;
            if (curr == *tptr)
            {
                (*tptr)->right = new;
                new->left = *tptr;
                new->right = NULL;
                *tptr = new;
            }
            else
            {
                new->right = curr->right;
                new->left = curr;
                curr->right = new;
            }

            flag = 1;
            break;
        }
        curr = curr->right;
    }

    if (!flag)
    {
        printf("Invalid Target\n");
        return;
    }
}

void displayList(Dnode *hptr)
{
    Dnode *temp = hptr;
    printf("NULL<->");
    while (temp != NULL)
    {
        printf("%d<->", temp->data);
        temp = temp->right;
    }
    printf("NULL\n");
}

int main()
{
    Dnode *head = NULL;
    Dnode *tail = NULL;
    int ch, val, ele, tar;

    while (1)
    {
        printf("Enter:\n 1. Add items\n 2. Insert after Target\n 3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value\n");
            scanf("%d", &ele);
            insertAtEnd(&head, &tail, ele);
            displayList(head);
            break;
        case 2:
            printf("Enter target & value\n");
            scanf("%d%d", &tar, &val);
            insertAfterTarget(&head, &tail, tar, val);
            displayList(head);
            break;
        case 3:
            printf("EOF\n");
            exit(0);
        default:
            printf("Wrong Choice!\n");
        }
    }

    return 0;
}