#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct dnode
{
    int val;
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
    new->right = null; // since it is the new last node
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

int main()
{
    Dnode *left, *right;
    head = NULL;
    tail = NULL;
}