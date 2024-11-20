#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *data;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (int *)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to check if a stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int val)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = val;
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Queue structure using two stacks
typedef struct queue
{
    Stack *stack1;
    Stack *stack2;
} Queue;

// Function to create a queue
Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

// Enqueue operation
void enqueue(Queue *queue, int val)
{
    push(queue->stack1, val);
}

// Dequeue operation
int dequeue(Queue *queue)
{
    if (isEmpty(queue->stack2))
    {
        // Transfer all elements from stack1 to stack2 if stack2 is empty
        while (!isEmpty(queue->stack1))
        {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    // If stack2 is still empty, the queue is empty
    if (isEmpty(queue->stack2))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    return pop(queue->stack2);
}

// Function to display the queue
void displayQueue(Queue *queue)
{
    if (!isEmpty(queue->stack2))
    {
        for (int i = queue->stack2->top; i >= 0; i--)
        {
            printf("%d <- ", queue->stack2->data[i]);
        }
    }
    if (!isEmpty(queue->stack1))
    {
        for (int i = 0; i <= queue->stack1->top; i++)
        {
            printf("%d <- ", queue->stack1->data[i]);
        }
    }
    printf("NULL\n");
}

// Main function
int main()
{
    int capacity = 10; // Define queue capacity
    Queue *queue = createQueue(capacity);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("Queue after enqueues:\n");
    displayQueue(queue);

    printf("Dequeue: %d\n", dequeue(queue));
    printf("Queue after dequeue:\n");
    displayQueue(queue);

    enqueue(queue, 40);
    printf("Queue after enqueue 40:\n");
    displayQueue(queue);

    printf("Dequeue: %d\n", dequeue(queue));
    printf("Queue after dequeue:\n");
    displayQueue(queue);

    printf("Dequeue: %d\n", dequeue(queue));
    printf("Queue after dequeue:\n");
    displayQueue(queue);

    printf("Dequeue: %d\n", dequeue(queue));
    printf("Queue after dequeue:\n");
    displayQueue(queue);

    printf("Dequeue: %d\n", dequeue(queue));
    printf("Queue after dequeue:\n");
    displayQueue(queue);

    return 0;
}
