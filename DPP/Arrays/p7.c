/*
    Two Stacks
    - Stack 1 grows from top to end
    - Stack 2 grows from end to top
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    int arr[MAX]; // Shared array for two stacks
    int top1;     // Top of Stack 1
    int top2;     // Top of Stack 2
} TwoStacks;

// Initialize the stacks
void initialize(TwoStacks *stacks)
{
    stacks->top1 = -1;  // Stack 1 starts from index -1 (empty)
    stacks->top2 = MAX; // Stack 2 starts from the end of the array
}

// Push an element into Stack 1
void push1(TwoStacks *stacks, int value)
{
    if (stacks->top1 + 1 == stacks->top2)
    { // tops overlap
        printf("Stack Overflow! No space available.\n");
        return;
    }
    stacks->arr[++stacks->top1] = value; // growing to end (increment top)
    printf("Pushed %d to Stack 1.\n", value);
}

// Push an element into Stack 2
void push2(TwoStacks *stacks, int value)
{
    if (stacks->top1 + 1 == stacks->top2)
    {
        printf("Stack Overflow! No space available.\n");
        return;
    }
    stacks->arr[--stacks->top2] = value; // growing to start (decrement top)
    printf("Pushed %d to Stack 2.\n", value);
}

// Pop an element from Stack 1
int pop1(TwoStacks *stacks)
{
    if (stacks->top1 == -1)
    {
        printf("Stack Underflow! Stack 1 is empty.\n");
        return -1;
    }
    int value = stacks->arr[stacks->top1--];
    printf("Popped %d from Stack 1.\n", value);
    return value;
}

// Pop an element from Stack 2
int pop2(TwoStacks *stacks)
{
    if (stacks->top2 == MAX)
    {
        printf("Stack Underflow! Stack 2 is empty.\n");
        return -1;
    }
    int value = stacks->arr[stacks->top2++];
    printf("Popped %d from Stack 2.\n", value);
    return value;
}

void displayFullStack(TwoStacks *stacks)
{
    printf("\nCurrent state of the array:\n");
    for (int i = 0; i < MAX; i++)
    {
        if (i <= stacks->top1)
            printf("%d ", stacks->arr[i]);
        else if (i >= stacks->top2)
            printf("%d ", stacks->arr[i]);
        else
            printf("_ "); // Empty space between the stacks
    }
    printf("\n");
}

int main()
{
    TwoStacks stacks;
    initialize(&stacks);

    int choice, value;

    while (1)
    {
        printf("\nChoose an operation:\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push to Stack 1: ");
            scanf("%d", &value);
            push1(&stacks, value);
            break;

        case 2:
            printf("Enter value to push to Stack 2: ");
            scanf("%d", &value);
            push2(&stacks, value);
            break;

        case 3:
            pop1(&stacks);
            break;

        case 4:
            pop2(&stacks);
            break;

        case 5:
            printf("Exiting program. Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }

        displayFullStack(&stacks);
    }

    return 0;
}