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

int deleteByValue(Node **hptr, int key)
{
    Node *h = *hptr, *curr = h, *prev = NULL;
    int flag = 0, count = 0, val;
    if (curr == NULL)
    {
        printf("Empty List\n");
        return INT_MIN;
    }

    while (curr != NULL)
    {
        if (curr->data == key)
        {
            flag = 1;
            count++;

            if (prev == NULL)
            {
                *hptr = curr->link;
                free(curr);
                curr = *hptr;
            }
            else
            {
                prev->link = curr->link;
                free(curr);
                curr = prev->link;
            }
        }
        else
        {
            prev = curr;
            curr = curr->link;
        }
    }

    if (!flag)
    {
        printf("Key not found in the list.\n");
        return INT_MIN;
    }

    return count;
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
        printf("Enter:\n 1. Add items\n 2. Delete by Value\n 3. Exit\n");
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
            printf("Enter value to be deleted\n");
            scanf("%d", &num);
            val = deleteByValue(&head, num);
            if (val != INT_MIN)
                printf("Deleted %d occurrence(s) of key %d.\n", val, num);
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