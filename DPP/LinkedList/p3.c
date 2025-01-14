#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *insertAtEnd(Node *head, int val)
{
    Node *new = (Node *)malloc(sizeof(Node));
    if (new != NULL)
    {
        new->data = val;
        new->link = NULL;
        if (head == NULL)
        {
            head = new;
            return head;
        }
        else
        {
            Node *curr = head;
            while (curr->link != NULL)
            {
                curr = curr->link;
            }
            curr->link = new;
        }
        return head;
    }
    else
    {
        printf("Memory Allocation failed\n");
        exit(0);
    }
}

void displayList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int listLength(Node *head)
{
    Node *curr = head;
    int c = 0;
    while (curr != NULL)
    {
        c++;
        curr = curr->link;
    }

    return c;
}

void splitList(Node *head)
{
    int l = listLength(head);
    Node *h1 = NULL, *h2 = NULL, *curr = head;
    int i = 1, q;
    if (l % 2 == 0)
        q = l / 2;
    else
        q = l / 2 + 1;

    while (curr != NULL)
    {
        if (i <= q)
        {
            h1 = insertAtEnd(h1, curr->data);
        }
        else
        {
            h2 = insertAtEnd(h2, curr->data);
        }
        i++;
        curr = curr->link;
    }

    printf("List 1:\n");
    displayList(h1);
    printf("List 2:\n");
    displayList(h2);
}

int main()
{
    Node *head = NULL;
    int num, val, pos, ch;

    while (1)
    {
        printf("Enter:\n 1. Add items\n 2. Split List\n 3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value\n");
            scanf("%d", &num);
            head = insertAtEnd(head, num);
            displayList(head);
            break;
        case 2:
            printf("Splitted List\n");
            splitList(head);
            break;
        case 3:
            printf("EOF\n");
            exit(0);
        default:
            printf("Wrong Choice!\n");
        }
    }

    return 0;
}