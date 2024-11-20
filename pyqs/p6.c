#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct node
{
    char data;
    struct node *link;
} Node;

Node *insertAtBeginning(Node *head, char val)
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

int checkPalindrome(Node *hptr) {
    char *res = (char*)malloc(MAX*sizeof(char));
    char *res2 = (char*)malloc(MAX*sizeof(char));
    int x = 0, y = 0, i;
    Node *curr = hptr;

    while(curr != NULL) {
        res[x++] = curr->data;
        curr = curr->link;
    }
    res[x] = '\0';

    for(i=x-1; i>=0; i--)
        res2[y++] = res[i];
    res[y] = '\0';

    printf("res1: %s, res2: %s\n", res, res2);

    if(strcmp(res, res2)) {
        free(res);
        free(res2);
        return 0;
    } else {
        free(res);
        free(res2);
        return 1;
    }
}

void displayList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%c -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;
    int val, ch;
    char c;

    printf("Enter the elements of the SLL. Press -1 to stop\n");
    while (1)
    {
        scanf(" %c", &c);
        head = insertAtBeginning(head, c);
        printf("Continue?\n");
        scanf("%d", &ch);
        if (ch == -1)
            break;
    }

    printf("The List:\n");
    displayList(head);

    val = checkPalindrome(head);
    if(val)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}