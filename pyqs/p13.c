#include <stdio.h>
#include <stdlib.h>

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

int insertAfterTarget(Dnode **hptr, Dnode **tptr, int n, int t)
{
    Dnode *curr = *hptr, *prev = NULL;
    int f = 0;
    while (curr != NULL)
    {
        if (curr->data == t)
        {
            Dnode *new = (Dnode *)malloc(sizeof(Dnode));
            new->data = n;
            new->left = curr;

            if (curr == (*hptr) && (*hptr)->right == NULL) // single node
            { 
                new->right = NULL;
                curr->right = new;
                *tptr = new;
            }
            else if (curr == (*tptr)) // tail node
            {
                new->right = NULL;
                curr->right = new;
                *tptr = new;
            }
            else
            {
                new->right = curr->right;
                (curr->right)->left = new;
                curr->right = new;
            }
            f = 1;
            return f;
        }

        prev = curr;
        curr = curr->right;
    }

    return f;
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
    int ch, val, ele;

    while (1)
    {
        printf("Enter:\n 1. IAE\n 2. IAT\n 3. Exit\n");
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
            printf("Enter element & target.\n");
            scanf("%d%d", &ele, &val);
            int res = insertAfterTarget(&head, &tail, ele, val);
            if (res)
            {
                print_DLL(head);
            }
            else
            {
                printf("Target not found\n");
            }
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