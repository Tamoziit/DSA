#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct Stack {
    Node* node;
    struct Stack* next;
} Stack;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void push(Stack** top, Node* node) {
    Stack* newStackNode = (Stack*)malloc(sizeof(Stack));
    newStackNode->node = node;
    newStackNode->next = *top;
    *top = newStackNode;
}

Node* pop(Stack** top) {
    if (*top == NULL) return NULL;
    Stack* temp = *top;
    Node* node = temp->node;
    *top = (*top)->next;
    free(temp);
    return node;
}

int isEmpty(Stack* top) {
    return top == NULL;
}

void inorderIterativeTraversal(Node *rptr)
{
    Stack *stack = NULL;

    while(rptr != NULL || !isEmpty(stack))
    {
        while(rptr != NULL)
        {
            push(&stack, rptr);
            rptr = rptr->left;
        }

        rptr = pop(&stack);
        printf("%d ", rptr->data);
        rptr = rptr->right;
    }
}

int main() {
    Node* root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);
    root->left->left = createNode(5);
    root->left->right = createNode(15);
    root->right->left = createNode(25);
    root->right->right = createNode(35);

    printf("In-Order Traversal: ");
    inorderIterativeTraversal(root);
    printf("\n");

    return 0;
}