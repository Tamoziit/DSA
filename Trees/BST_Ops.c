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
        new->left = new->right = NULL;
        new->data = val;
        *rptr = new;
        return;
    }
    else
    {
        if (root->data > val)
            insertBST(&root->left, val);
        else if (root->data < val)
            insertBST(&root->right, val);
        else
        {
            printf("Duplicate insertion not possible\n");
            return;
        }
    }
}

void inorderTraversal(Tnode *rptr)
{
    if(rptr == NULL)
        return;
    
    inorderTraversal(rptr->left);
    printf("%d ", rptr->data);
    inorderTraversal(rptr->right);
}

int getTreeHeight(Tnode *rptr)
{
    if (rptr == NULL)
        return -1;

    int lh, rh;
    lh = getTreeHeight(rptr->left);
    rh = getTreeHeight(rptr->right);

    if (rh >= lh)
        rptr->h = rh + 1;
    else
        rptr->h = lh + 1;

    return rptr->h;
}

void inorderHeight(Tnode *rptr)
{
    if (rptr == NULL)
        return;

    inorderHeight(rptr->left);
    printf("%d:(%d) ", rptr->data, rptr->h);
    inorderHeight(rptr->right);
}

Tnode *findSuccessor(Tnode *rptr)
{
    while (rptr->left != NULL)
        rptr = rptr->left;
    return rptr;
}

Tnode *deleteBST(Tnode *rptr, int key, int *status)
{
    if (rptr == NULL)
        return NULL;

    if (key < rptr->data)
    {
        rptr->left = deleteBST(rptr->left, key, status);
    }
    else if (key > rptr->data)
    {
        rptr->right = deleteBST(rptr->right, key, status);
    }
    else
    {
        *status = 1;
        Tnode *temp;

        if (rptr->left == NULL)
        {
            temp = rptr->right;
            free(rptr);
            return temp;
        }
        else if (rptr->right == NULL)
        {
            temp = rptr->left;
            free(rptr);
            return temp;
        }

        temp = findSuccessor(rptr->right);
        rptr->data = temp->data;
        rptr->right = deleteBST(rptr->right, temp->data, status);
    }

    return rptr;
}

Tnode *searchNode(Tnode *rptr, int key)
{
    if (rptr == NULL || rptr->data == key)
        return rptr;
    else
    {
        if(rptr->data > key)
        {
            printf("%d; Going Left\n", rptr->data);
            return searchNode(rptr->left, key);
        }
        else if(rptr->data < key)
        {
            printf("%d; Going Right\n", rptr->data);
            return searchNode(rptr->right, key);
        }
    }
}

int main()
{
    Tnode *start = NULL, *temp = NULL;
    int ch, val, status = 0, h;

    while(1)
    {
        printf("Enter\n 1. Insert BST\n 2. Inorder Traversal & height\n 3. Inorder Height\n 4. Delete Node\n 5. Search Node\n 6. Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter value\n");
                scanf("%d", &val);
                insertBST(&start, val);
                h = getTreeHeight(start);
                break;
            case 2:
                inorderTraversal(start);
                printf("\n");
                h = getTreeHeight(start);
                printf("Height = %d\n", h);
                break;
            case 3:
                inorderHeight(start);
                printf("\n");
                break;
            case 4:
                printf("Enter element to be deleted\n");
                scanf("%d", &val);
                temp = deleteBST(start, val, &status);
                if(status)
                {
                    printf("Element found & deleted\n");
                    h = getTreeHeight(start);
                }
                else
                {
                    printf("Element not found\n");
                    h = getTreeHeight(start);
                }
                break;
            case 5:
                printf("Enter element to be searched\n");
                scanf("%d", &val);
                temp = searchNode(start, val);
                if(temp != NULL)
                {
                    printf("Element Found\n");
                } else {
                    printf("Element not found\n");
                }
                break;
            case 6:
                printf("EOP\n");
                exit(0);
            default:
                printf("Wrong Choice!\n");
        }
    }

    return 0;
}