#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a queue node
typedef struct QueueNode
{
    char binary[20]; // To store binary strings
    struct QueueNode *next;
} QueueNode;

// Define the queue
typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

// Function to initialize a queue
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue an element into the queue
void enqueue(Queue *q, const char *binary)
{
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    strcpy(temp->binary, binary);
    temp->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to dequeue an element from the queue
char *dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        return NULL;
    }
    QueueNode *temp = q->front;
    char *binary = (char *)malloc(strlen(temp->binary) + 1);
    strcpy(binary, temp->binary);
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return binary;
}

// Function to check if the queue is empty
int isEmpty(Queue *q)
{
    return q->front == NULL;
}

// Function to generate binary numbers using a queue
void generateBinary(int n)
{
    Queue *q = createQueue();
    enqueue(q, "1"); // Start with the first binary number
    char zeroPrefix[20], onePrefix[20];

    for (int i = 1; i <= n; i++)
    {
        char *current = dequeue(q);

        // Print the current binary number
        printf("%s\n", current);

        // Generate the next binary numbers and enqueue them
        snprintf(zeroPrefix, sizeof(zeroPrefix), "%s0", current);
        snprintf(onePrefix, sizeof(onePrefix), "%s1", current);
        enqueue(q, zeroPrefix);
        enqueue(q, onePrefix);

        free(current);
    }

    // Clean up memory
    while (!isEmpty(q))
    {
        free(dequeue(q));
    }
    free(q);
}

// Main function
int main()
{
    int n;
    printf("Enter the number of binary numbers to generate: ");
    scanf("%d", &n);
    generateBinary(n);
    return 0;
}
