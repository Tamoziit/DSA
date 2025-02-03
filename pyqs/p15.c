#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct dnode
{
    int data;
    struct dnode *left;
    struct dnode *right;
} Dnode;

void dll_insert_at_end(Dnode **hptr, Dnode **tptr, int val)
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

void dll_reverseList(Dnode **hptr, Dnode **tptr)
{
    if (*hptr == NULL)
    {
        printf("Empty List\n");
        return;
    }

    Dnode *curr = *hptr, *temp;
    while (curr != NULL)
    {
        temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
        curr = curr->left;
    }

    temp = *hptr;
    *hptr = *tptr;
    *tptr = temp;
}

void print_DLL(Dnode *hptr)
{
    Dnode *temp = hptr;
    printf("NULL->");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->right;
    }
    printf("NULL\n");
}

int main()
{
    Dnode *head = NULL;
    Dnode *tail = NULL;
    int ch, val, pos, ele;

    while (1)
    {
        printf("Enter:\n 1. IAE\n 2. Reverse\n 3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter ele.\n");
            scanf("%d", &val);
            dll_insert_at_end(&head, &tail, val);
            print_DLL(head);
            break;
        case 2:
            dll_reverseList(&head, &tail);
            print_DLL(head);
            break;
        case 3:
            printf("End of prog\n");
            exit(0);
        default:
            printf("Wrong Choice\n");
        }
    }

    return 0;
}