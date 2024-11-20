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

int deleteAtBeginning(Node **hptr)
{
    Node *h = *hptr;
    if (h == NULL)
    {
        printf("Empty List\n");
        return INT_MIN;
    }
    else
    {

        Node *temp = h;
        h = h->link;
        int v = temp->data;
        free(temp);
        *hptr = h;
        return v;
    }
}

int deleteAtEnd(Node **hptr)
{
    Node *curr = *hptr, *prev = NULL;
    int val;
    if (curr == NULL)
    {
        printf("Empty List\n");
        return INT_MIN;
    }
    while (curr->link != NULL)
    {
        prev = curr;
        curr = curr->link;
    }
    if (prev != NULL)
    {
        prev->link = NULL;
        val = curr->data;
        free(curr);
    }
    else
    {
        *hptr = NULL;
        val = curr->data;
        free(curr);
    }
    return val;
}

int deleteMultiple(Node **hptr, int val)
{
    int c = 0;
    if (*hptr == NULL)
    {
        printf("Empty List\n");
        return INT_MIN;
    }

    Node *curr = *hptr, *prev = NULL, *temp;

    while (curr != NULL)
    {
        if (curr->data == val)
        {
            temp = curr->link; // Saving the next node
            if (curr == *hptr)
            {
                deleteAtBeginning(hptr);
            }
            else if (curr->link == NULL)
            {
                deleteAtEnd(hptr);
            }
            else
            {
                prev->link = curr->link;
                free(curr);
            }
            c++;
            curr = temp; // Moving to the next node
        }
        else
        {
            prev = curr;
            curr = curr->link;
        }
    }

    return c == 0 ? INT_MIN : c;
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
    int c, val, ch;

    printf("Enter the elements of the SLL. Press -1 to stop\n");
    while (1)
    {
        scanf("%d", &val);
        head = insertAtBeginning(head, val);
        printf("Continue?\n");
        scanf("%d", &ch);
        if (ch == -1)
            break;
    }

    printf("The List:\n");
    displayList(head);

    printf("Enter val:\n");
    scanf("%d", &val);
    c = deleteMultiple(&head, val);
    if (c != INT_MIN)
    {
        printf("Deleted count = %d\n", c);
        displayList(head);
    }
    else
    {
        printf("No such element found\n");
    }

    return 0;
}