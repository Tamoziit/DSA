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

void sortList(Node **h)
{
    if (*h == NULL)
    {
        printf("Empty List\n");
        return;
    }

    int swapped;
    Node *ptr1;
    Node *lptr = NULL; // Marks the portion already sorted

    do
    {
        swapped = 0;
        ptr1 = *h;

        while (ptr1->link != lptr)
        {
            if (ptr1->data > ptr1->link->data)
            {
                // Swapping the data
                int temp = ptr1->data;
                ptr1->data = ptr1->link->data;
                ptr1->link->data = temp;

                swapped = 1;
            }
            ptr1 = ptr1->link;
        }
        lptr = ptr1; // Updating last sorted node
    } while (swapped);
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

    printf("After sorting\n");
    sortList(&head);
    displayList(head);

    return 0;
}