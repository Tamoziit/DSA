#include <stdio.h>
#include <stdlib.h>

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
        }
        else
        {
            Node *temp = head;
            while (temp->link != NULL)
            {
                temp = temp->link; // traversing the list
            }
            temp->link = new; // linking new entry to prev. node
        }
    }
    else
    {
        printf("Memory Allocation failed\n");
        exit(0);
    }
    return head;
}

Node *insertAtPosition(Node *head, int val, int pos)
{
    Node *new = (Node *)malloc(sizeof(Node));
    if (new != NULL)
    {
        new->data = val;
        new->link = NULL;

        // If inserting at the beginning (position 1)
        if (pos == 1)
        {
            new->link = head;
            head = new;
        }
        else
        {
            Node *temp = head;
            // Traverse to the node before the desired position
            for (int i = 1; i < pos - 1 && temp != NULL; i++)
            {
                temp = temp->link;
            }
            // If position is beyond the current list length
            if (temp == NULL)
            {
                printf("Position out of bounds\n");
                free(new);
            }
            else
            {
                // Insert the new node
                new->link = temp->link;
                temp->link = new; // address of prev node
            }
        }
    }
    else
    {
        printf("Memory Allocation failed\n");
        exit(0);
    }
    return head;
}

Node *createInitialList(int num)
{
    Node *head = NULL;
    Node *temp = NULL;
    Node *new = NULL;
    int value;

    for (int i = 0; i < num; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        new = (Node *)malloc(sizeof(Node));
        if (new != NULL)
        {
            new->data = value;
            new->link = NULL;
            if (head == NULL)
            {
                head = new;
            }
            else
            {
                temp->link = new;
            }
            temp = new;
        }
        else
        {
            printf("Memory Allocation failed\n");
            exit(0);
        }
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