#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

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

void twoLists(Node *hptr)
{
    int c = 0;
    Node *curr = hptr;
    Node *sptr = NULL, *lptr = NULL;
    while (curr != NULL)
    {
        c++;
        curr = curr->link;
    }

    int mid = (c + 1) / 2;
    int x = 0;
    curr = hptr;

    while (x < mid)
    {
        sptr = insertAtEnd(sptr, curr->data);
        curr = curr->link;
        x++;
    }
    while (curr != NULL)
    {
        lptr = insertAtEnd(lptr, curr->data);
        curr = curr->link;
    }

    displayList(sptr);
    displayList(lptr);
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

    twoLists(head);
    return 0;
}