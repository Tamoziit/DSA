#include <stdio.h>
#include <stdlib.h>

// Define a structure for singly linked list nodes
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *insertAtEnd(Node *head, int val)
{
    Node *new = (Node *)malloc(sizeof(Node));
    if (new != NULL)
    {
        new->data = val;
        new->next = NULL;
        if (head == NULL)
        {
            head = new;
            return head;
        }
        else
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = new;
        }
        return head;
    }
    else
    {
        printf("Memory Allocation failed\n");
        exit(0);
    }
}

// Function to perform insertion sort on the linked list
Node* insertionSortList(Node* head) {
    if (!head || !head->next) return head;

    // Dummy node to act as a placeholder for the sorted list
    Node *dummy = NULL;
    dummy = insertAtEnd(dummy, 0);
    dummy->next = NULL;

    // Traverse the original list
    Node* curr = head;
    while (curr) {
        // Extract the current node
        Node* next = curr->next;

        // Find the position to insert in the sorted list
        Node* prev = dummy;
        while (prev->next && prev->next->data < curr->data) {
            prev = prev->next;
        }

        // Insert the current node into the sorted list
        curr->next = prev->next;
        prev->next = curr;

        // Move to the next node in the original list
        curr = next;
    }

    // Get the sorted list and free the dummy node
    Node* sortedHead = dummy->next;
    free(dummy);
    return sortedHead;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to test the algorithm
int main() {
    Node *head = NULL;
    int num, ch;

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

    printf("Original list: ");
    printList(head);

    // Sort the list
    head = insertionSortList(head);

    printf("Sorted list: ");
    printList(head);

    freeList(head);

    return 0;
}