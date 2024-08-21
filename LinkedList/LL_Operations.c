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
    Node *new = (Node *)malloc(1 * sizeof(Node));
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
                curr = temp->link; // traversing the list
            }
            curr->link = new; // linking new entry to prev. node
        }
        return head;
    }
    else
    {
        printf("Memory Allocation failed\n");
        exit(0);
    }
}

Node *insertAtPosition(Node *head, int val, int pos)
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
            new->link = curr->link; // updating pos. by creating new link and breaking down the old one
            curr->link = new;
        }
        curr = curr->link; // traversal step
    }
    if (pos > c + 1 || pos <= 0)
    {
        printf("Invalid position\n");
    }
    return h;
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
        prev->link = NULL; // last node after deletion
        val = curr->data;
        free(curr); // deleting curr which stores last ele., after complete traversal
    }
    else
    { // only one node edge case
        *hptr = NULL;
        val = curr->data;
        free(curr);
    }
    return val;
}

int deleteAtPosition(Node **hptr, int pos)
{
    Node *h = *hptr, *curr = h, *prev = NULL;
    int c = 0, val;
    if (pos == 1)
    {
        val = deleteAtBeginning(&h);
        return val;
    }
    while (curr != NULL)
    {
        c++;
        if (c == pos)
        {
            prev->link = curr->link;
            val = curr->data;
            free(curr);
        }
        prev = curr;
        curr = curr->link;
    }
    if (pos > c + 1 || pos <= 0)
    {
        printf("Invalid position\n");
        return INT_MIN;
    }
    return val;
}

int deleteByValue(Node **hptr, int key)
{
    Node *h = *hptr, *curr = h, *prev = NULL;
    int flag = 0, val;
    while (curr != NULL)
    {
        if (curr->data == key)
        {
            flag = 1;
            break;
        }
        // next node updates
        prev = curr;
        curr = curr->link;
    }
    if (flag == 0)
    {
        printf("Element not found\n");
        return INT_MIN;
    }
    if (prev == NULL) // 1st element deletion
    {
        h = deleteAtBeginning(&h);
    }
    else
    {                            // deleting at any other pos. except pos 1
        prev->link = curr->link; // before deletion --> prev->curr->next. after deleting curr --> prev->next
        val = curr->link;
        free(curr);
    }
    return val;
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
    int num, value, choice;

    printf("Enter the number of elements you want to insert initially: ");
    scanf("%d", &num);

    head = createInitialList(num);
    displayList(head);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    head = insertAtBeginning(head, value);
    displayList(head);

    head = insertAtEnd(head, value);
    displayList(head);

    int pos;
    printf("Enter pos & value\n");
    scanf("%d%d", &pos, &value);
    head = insertAtPosition(head, value, pos);
    displayList(head);

    return 0;
}