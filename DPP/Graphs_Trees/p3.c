#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *queue[100];
int front = -1;
int rear = -1;
int count = 0;

int isEmptyQueue()
{
    if(count)
        return 0;
    return 1;
}

void enqueue(Node *rptr)
{
    queue[++rear] = rptr;
    if (rear == 0)
        front = 0;
    count++;
}

Node *dequeue()
{
    if (isEmptyQueue()) return NULL;
    Node *temp = queue[front++];
    count--;
    return temp;
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isCompleteOrAlmostComplete(Node *rptr)
{
    if (rptr == NULL)
        return 1;

    enqueue(rptr);
    int encounteredNull = 0;

    while (!isEmptyQueue())
    {
        Node *curr = dequeue();
        if (curr == NULL)
        {
            encounteredNull = 1;
            continue;
        }
        else {
            if(encounteredNull)
                return 0;
            enqueue(curr->left);
            enqueue(curr->right);
        }
        encounteredNull = 0;
    }

    return 1;
}

int main()
{
    int res = 0;

    Node *root1 = createNode(20);
    root1->left = createNode(10);
    root1->right = createNode(30);
    root1->left->left = createNode(5);
    root1->left->right = createNode(15);
    root1->right->left = createNode(25);
    root1->right->right = createNode(35);

    res = isCompleteOrAlmostComplete(root1);
    if (res)
    {
        printf("Tree 1 is: Complete or Almost Complete\n");
    }
    else
    {
        printf("Tree 1 is: Not Complete or Almost Complete\n");
    }

    res = 0;

    Node *root2 = createNode(20);
    root2->left = createNode(10);
    root2->right = createNode(30);
    root2->left->left = createNode(5);
    //root2->left->right = createNode(15);
    //root2->right->left = createNode(25);
    root2->right->right = createNode(35);

    res = isCompleteOrAlmostComplete(root2);
    if (res)
    {
        printf("Tree 2 is: Complete or Almost Complete\n");
    }
    else
    {
        printf("Tree 2 is: Not Complete or Almost Complete\n");
    }

    return 0;
}
