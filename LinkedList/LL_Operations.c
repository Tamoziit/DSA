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
                curr = curr->link; // traversing the list
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

Node *insertAtPosition(Node *h, int val, int pos)
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
    if (curr == NULL)
    {
        printf("Empty List\n");
        return INT_MIN;
    }
    if (pos == 1)
    {
        val = deleteAtBeginning(&h);
        *hptr = h; // Update the head pointer
        return val;
    }
    while (curr != NULL)
    {
        c++;
        if (c == pos)
        {
            if (prev != NULL) // Check if prev is not NULL
            {
                prev->link = curr->link;
            }
            val = curr->data;
            free(curr);
            return val;
        }
        prev = curr;
        curr = curr->link;
    }
    if (pos > c || pos <= 0)
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
        val = deleteAtBeginning(&h);
    }
    else
    {                            // deleting at any other pos. except pos 1
        prev->link = curr->link; // before deletion --> prev->curr->next. after deleting curr --> prev->next
        val = curr->data;
        free(curr);
    }
    return val;
}

Node *reverseLinkedList(Node *h)
{
    Node *curr = h, *prev = NULL, *next, *temp;
    if (h == NULL)
    {
        printf("Empty List\n");
        return h;
    }
    if (curr != NULL)
    {
        next = curr->link;
        temp = next;
    }
    while (next != NULL)
    {
        // Reversing
        curr->link = prev;
        prev = curr;
        curr = next;
        next = next->link;
    }
    h = curr;
    curr->link = prev;

    return h;
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

    printf("Enter the elements of the SLL. Press -1 to stop\n");
    while (1)
    {
        scanf("%d", &num);
        head = insertAtEnd(head, num);
        printf("Continue?\n");
        scanf("%d", &ch);
        if (ch == -1)
            break;
    }

    printf("The List:\n");
    displayList(head);

    while (1)
    {
        printf("Enter:\n 1. IAB\n 2. IAE\n 3. IAP\n 4. DAB\n 5. DAE\n 6. DAP\n 7. DBV\n 8. Reverse\n 9. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter ele\n");
            scanf("%d", &val);
            head = insertAtBeginning(head, val);
            displayList(head);
            break;
        case 2:
            printf("Enter ele\n");
            scanf("%d", &val);
            head = insertAtEnd(head, val);
            displayList(head);
            break;
        case 3:
            printf("Enter ele. & pos.\n");
            scanf("%d%d", &val, &pos);
            head = insertAtPosition(head, val, pos);
            displayList(head);
            break;
        case 4:
            val = deleteAtBeginning(&head);
            if (val != INT_MIN)
            {
                printf("Deleted Value = %d\n", val);
                displayList(head);
            }
            break;
        case 5:
            val = deleteAtEnd(&head);
            if (val != INT_MIN)
            {
                printf("Deleted Value = %d\n", val);
                displayList(head);
            }
            break;
        case 6:
            printf("Enter position\n");
            scanf("%d", &pos);
            val = deleteAtPosition(&head, pos);
            if (val != INT_MIN)
            {
                printf("Deleted Value = %d\n", val);
                displayList(head);
            }
            break;
        case 7:
            printf("Enter value\n");
            scanf("%d", &num);
            val = deleteByValue(&head, num);
            if (val != INT_MIN)
            {
                printf("Deleted Value = %d\n", val);
                displayList(head);
            }
            break;
        case 8:
            head = reverseLinkedList(head);
            if (head != NULL)
                displayList(head);
            break;
        case 9:
            printf("End of Program\n");
            exit(0);
        default:
            printf("Wrong Choice!\n");
        }
    }

    return 0;
}