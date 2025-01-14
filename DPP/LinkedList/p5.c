#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct circNode {
    int data;
    struct circNode *link;
} CNode;

CNode *insertAtBeginning(CNode *head, int val)
{
    CNode *new = (CNode*)malloc(sizeof(CNode));
    if(new == NULL)
    {
        printf("Memory Alloc. Failed\n");
        exit(0);
    }
    new->data = val;

    if(head == NULL)
    {
        head = new;
        new->link = new;
    }
    else {
        CNode *curr = head;
        new->link = curr;
        while(curr->link != head)
        {
            curr = curr->link;
        }
        curr->link=new;
        head = new;
    }

    return head;
}

int deleteAtEnd(CNode **head)
{
    CNode *curr = *head, *prev = NULL;
    int val;
    if(curr == NULL)
    {
        printf("Empty List\n");
        return INT_MIN;
    }

    if(curr->link == *head)
    {
        *head = NULL;
        val = curr->data;
        free(curr);
        return val;
    }

    while(curr->link != *head)
    {
        prev = curr;
        curr = curr->link;
    }

    val = curr->data;
    prev->link = *head;
    free(curr);
    return val;
}

void displayList(CNode *head)
{
    if (head == NULL)
    {
        printf("Head->NULL\n");
        return;
    }

    CNode *curr = head;
    printf("Head->");
    do
    {
        printf("%d->", curr->data);
        curr = curr->link;
    } while (curr != head);
    printf("Head\n");
}

int main()
{
    CNode *head = NULL;
    int num, val, ch;

    while (1)
    {
        printf("Enter:\n 1. Add items\n 2. Delete at End\n 3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value\n");
            scanf("%d", &num);
            head = insertAtBeginning(head, num);
            displayList(head);
            break;
        case 2:
            val = deleteAtEnd(&head);
            if (val != INT_MIN)
                printf("Deleted value = %d\n", val);
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