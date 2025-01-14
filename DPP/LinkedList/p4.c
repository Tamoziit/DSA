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
    if (new != NULL)
    {
        new->data = val;
        new->link = head;
        head = new;
    }
    else
    {
        printf("Mem. Alloc. failed\n");
        exit(0);
    }

    return head;
}

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

Node *insertAtPos(Node *head, int val, int pos)
{
    Node *curr = head, *prev = NULL;
    if (pos <= 0)
    {
        printf("Invalid Position\n");
        return head;
    }

    int c = 0;
    if (pos == 1)
    {
        head = insertAtBeginning(head, val);
        return head;
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
    if (pos > c + 1)
    {
        printf("Invalid Position\n");
        return head;
    }

    return head;
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

int main()
{
    Node *head = NULL;
    int num, val, pos, ch;

    while (1)
    {
        printf("Enter:\n 1. Add items\n 2. Insert at pos.\n 3. Exit\n");
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
            printf("Enter value & pos.\n");
            scanf("%d%d", &val, &pos);
            head = insertAtPos(head, val, pos);
            displayList(head);
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