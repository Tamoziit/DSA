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

void reverse(Dnode **hptr, Dnode **tptr)
{
    Dnode *curr = *hptr, *temp = NULL;
    while(curr != NULL)
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

int main()
{
    Dnode *head = NULL;
    Dnode *tail = NULL;
    int ch, pos, ele;
    printf("Enter the elements of the list. Press -1 to stop.\n");
    while (1)
    {
        scanf("%d", &ele);
        dll_insert_at_end(&head, &tail, ele);
        printf("Continue? ");
        scanf("%d", &ch);
        if (ch == -1)
            break;
    }

    printf("The list\n");
    print_DLL(head);
    reverse(&head, &tail);
    printf("The Reversed list\n");
    print_DLL(head);
    return 0;
}