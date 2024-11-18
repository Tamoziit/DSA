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

int findMin(Node *h)
{
    int min = h->data;
    Node *curr = h;

    while (curr != NULL)
    {
        if (curr->data < min)
            min = curr->data;
        curr = curr->link;
    }

    return min;
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

int deleteMin(Node **hptr, int min)
{
    Node *curr = (*hptr), *prev = NULL;
    if (curr == NULL)
    {
        printf("Empty List\n");
        return INT_MIN;
    }

    int val;
    while (curr != NULL)
    {
        if (curr->data == min)
        {
            if (*hptr == curr)
            {
                val = deleteAtBeginning(hptr);
                return val;
            }
            else if (curr->link == NULL)
            {
                val = deleteAtEnd(hptr);
                return val;
            }
            else
            {
                val = curr->data;
                prev->link = curr->link;
                free(curr);
                return val;
            }
        }

        prev = curr;
        curr = curr->link;
    }

    return INT_MIN;
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
    int min, val, ch;

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

    min = findMin(head);
    val = deleteMin(&head, min);
    if(val != INT_MIN)
    {
        printf("Deleted val = %d\n", val);
        displayList(head);
    }

    return 0;
}