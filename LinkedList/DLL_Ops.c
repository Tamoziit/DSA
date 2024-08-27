#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct dnode
{
    int data;
    struct dnode *left;
    struct dnode *right;
} Dnode;

void dll_insert_at_beginning(Dnode **hptr, Dnode **tptr, int val)
{
    Dnode *new = (Dnode *)malloc(sizeof(Dnode));
    new->data = val;
    new->right = *hptr; // address of the element which was previously pointed by head before insertion
    new->left = NULL;

    if (*hptr != NULL)       // More than 1 element in list case
        (*hptr)->left = new; // updating the left of prev ele which was initially pointed by head, to now store the address of newly inserted element
    *hptr = new;             // new head when list is empty initially

    if (*tptr == NULL) // no element in list initially case.
        *tptr = new;
}

void dll_insert_at_end(Dnode **hptr, Dnode **tptr, int val)
{
    Dnode *new = (Dnode *)malloc(sizeof(Dnode));
    new->data = val;
    new->right = NULL; // since it is the new last node
    new->left = *tptr; // address of the element which was previously the last node before insertion

    if (*tptr != NULL) // more than 1 node case
        (*tptr)->right = new;
    *tptr = new; // new tail after insertion when the list was initailly empty

    if (*hptr == NULL) // empty list initially
        *hptr = new;
}

int dll_insert_at_pos(Dnode **hptr, Dnode **tptr, int val, int pos)
{
    if (pos <= 0)
    {
        printf("Invalid pos\n");
        return INT_MIN;
    }
    if (pos == 1)
    {
        dll_insert_at_beginning(hptr, tptr, val);
        return 1;
    }

    int c = 1;
    Dnode *curr = *hptr, *next;
    while (c < pos - 1 && curr != NULL)
    {
        curr = curr->right;
        c++;
    }
    if (curr != NULL) // valid position
    {
        next = curr->right; // the element after current
        if (next == NULL)   // last element insertion
        {
            dll_insert_at_end(hptr, tptr, val);
            return 1;
        }
        else
        {
            Dnode *new = (Dnode *)malloc(sizeof(Dnode));
            // Inserting new element at the required pos --> in b/w current & next
            new->data = val;
            new->left = curr;
            new->right = next;

            // curr & next updates
            curr->right = new;
            next->left = new;
        }
    }
    else
    {
        printf("Invalid Position\n");
        return INT_MIN;
    }

    return 1; // success at insertion
}

int dll_delete_at_pos(Dnode **hptr, Dnode **tptr, int pos)
{
    int val;
    if (*hptr == NULL && *tptr == NULL)
    {
        printf("Empty List\n");
        return INT_MIN;
    }
    if (pos < 1)
    {
        printf("Invalid Pos.\n");
        return INT_MIN;
    }

    int c = 1;
    Dnode *curr = *hptr, *prev, *next;
    while (curr != NULL && c < pos)
    {
        curr = curr->right;
        c++;
    }
    if (curr != NULL)
    {
        prev = curr->left;
        next = curr->right;

        if (prev == NULL) // delete 1st ele
        {
            *hptr = curr->right;
        }
        else
        {
            prev->right = curr->right;
        }

        if (next == NULL) // delete last ele
        {
            *hptr = curr->left;
        }
        else
        {
            next->left = curr->left;
        }
    }
    else
    {
        printf("Invalid pos\n");
        return INT_MIN;
    }

    val = curr->data;
    free(curr);
    return val;
}

void reverse_DLL(Dnode **hptr, Dnode **tptr)
{
    Dnode *curr = *hptr, *temp;
    while (curr != NULL)
    {
        // Swapping for reversal
        temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
        curr = curr->left; // curr->right or next node is now actually at curr->left after swap
    }
    // swapping head & tail
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

    while (1)
    {
        printf("Enter:\n 1. IAB\n 2. IAE\n 3. IAP\n 4. DAB\n 5. DAE\n 6. DAP\n 7. DBV\n 8. Reverse\n 9. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter ele.\n");
            scanf("%d", &val);
            dll_insert_at_beginning(&head, &tail, val);
            print_DLL(head);
            break;
        case 2:
            printf("Enter ele.\n");
            scanf("%d", &val);
            dll_insert_at_end(&head, &tail, val);
            print_DLL(head);
            break;
        case 3:
            printf("Enter ele.\n");
            scanf("%d", &val);
            printf("Enter pos.\n");
            scanf("%d", &pos);
            ele = dll_insert_at_pos(&head, &tail, val, pos);
            print_DLL(head);
            break;
        case 6:
            printf("Enter pos\n");
            scanf("%d", &pos);
            val = dll_delete_at_pos(&head, &tail, pos);
            if (val != INT_MIN)
                printf("Deleted Value=%d\n", val);
            print_DLL(head);
            break;
        case 9:
            printf("End of prog\n");
            exit(0);
        default:
            printf("Wrong Choice\n");
        }
    }

    return 0;
}