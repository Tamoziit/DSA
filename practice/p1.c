/* Singly Linked List */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *insertAtBeginning(Node *head, int val)
{
    Node *new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
    {
        printf("Memory Alloc. Failed\n");
        exit(0);
    }
    new->data = val;

    if (head == NULL)
    {
        head = new;
        new->link = NULL;
    }
    else
    {
        new->link = head;
        head = new;
    }

    return head;
}

Node *insertAtEnd(Node *head, int val)
{
    Node *new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
    {
        printf("Memory Alloc. Failed\n");
        exit(0);
    }
    new->data = val;

    if (head == NULL)
    {
        head = new;
        new->link = NULL;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        while (curr->link != NULL)
            curr = curr->link;
        
        curr->link = new;
        new->link = NULL;
    }
    return head;
}

Node *insertAtPos(Node *h, int val, int pos)
{
    Node *curr = h;
    int c = 0;
    if (pos == 1)
    {
        h = insertAtBeginning(h, val);
        return h;
    }
    while (curr != NULL)
    {
        c++;
        if (pos == c + 1)
        {
            Node *new = (Node *)malloc(sizeof(Node));
            if (new == NULL)
            {
                printf("Memory Alloc. failed\n");
                exit(0);
            }
            new->data = val;
            new->link = curr->link;
            curr->link = new;
        }
        curr = curr->link;
    }
    if (pos > c + 1 || pos <= 0)
    {
        printf("Invalid position\n");
    }
    return h;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
    }

    Node *curr = head;
    while (curr != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->link;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;
    int ch, ele, val, pos;

    while (1)
    {
        printf("Enter\n 1. IAB\n 2. IAE\n 3. IAP\n 9. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value\n");
            scanf("%d", &ele);
            head = insertAtBeginning(head, ele);
            printList(head);
            break;
        case 2:
            printf("Enter value\n");
            scanf("%d", &ele);
            head = insertAtEnd(head, ele);
            printList(head);
            break;
        case 3:
            printf("Enter value\n");
            scanf("%d", &ele);
            printf("Enter position\n");
            scanf("%d", &pos);
            head = insertAtPos(head, ele, pos);
            printList(head);
            break;
        case 9:
            printf("EOP\n");
            exit(0);
        default:
            printf("Wrong Choice\n");
        }
    }

    return 0;
}