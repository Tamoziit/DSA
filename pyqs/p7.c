#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} Tnode;

void insertBST(Tnode **rptr, int val)
{
    Tnode *root = *rptr;
    if (root == NULL)
    {
        Tnode *new = (Tnode *)malloc(sizeof(Tnode));
        new->data = val;
        new->left = NULL;
        new->right = NULL;
        *rptr = new;
        return;
    }
    else if (root->data > val)
    {
        insertBST(&root->left, val);
    }
    else if (root->data < val)
    {
        insertBST(&root->right, val);
    }
    else
    {
        printf("Duplicate insertion not possible\n");
        return;
    }
}

void inorderTraversal(Tnode *rptr)
{
    if (rptr == NULL)
        return;

    inorderTraversal(rptr->left);
    printf("%d ", rptr->data);
    inorderTraversal(rptr->right);
}

int findMax(Tnode *rptr, int max)
{
    if (rptr == NULL)
        return max;

    findMax(rptr->left, max);
    if (rptr->data > max)
        max = rptr->data;
    findMax(rptr->right, max);
}

int main()
{
    Tnode *root = NULL;
    int ch, val, max = INT_MIN;

    while (1)
    {
        printf("Enter\n 1. Insert\n 2. Print\n 3. Find Max\n 4. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter val.\n");
            scanf("%d", &val);
            insertBST(&root, val);
            inorderTraversal(root);
            printf("\n");
            break;
        case 2:
            printf("The BST\n");
            inorderTraversal(root);
            printf("\n");
            break;
        case 3:
            max = findMax(root, max);
            printf("MAX = %d\n", max);
            break;
        case 4:
            printf("EOP\n");
            exit(0);
        default:
            printf("Wrong Choice\n");
        }
    }

    return 0;
}