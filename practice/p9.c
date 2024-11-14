/* BST */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    int h;
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
    }
    else if (root->data > val)
    {
        insertBST(root->left, val);
    }
    else if (root->data < val)
    {
        insertBST(root->right, val);
    }
    else
    {
        printf("Duplicate\n");
        return;
    }
}

void inorderTraversal(Tnode *rptr) {
    if(rptr == NULL) {
        return;
    }

    inorderTraversal(rptr->left);
    printf("%d ", rptr->data);
    inorderTraversal(rptr->right);
}

int getTreeHeight(Tnode *rptr) {
    if(rptr == NULL) {
        return -1;
    }

    int lh, rh;
    lh = getTreeHeight(rptr->left);
    rh = getTreeHeight(rptr->right);

    if(rh >= lh)
        rptr->h = rh+1;
    else
        rptr->h = lh=1;

    return rptr->h;
}

void inorderHeight(Tnode *rptr) {
    if(rptr == NULL) {
        return;
    }

    inorderHeight(rptr->left);
    printf("%d:(%d) ", rptr->data, rptr->h);
    inorderHeight(rptr->right);
}

