#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Stack functions
void push(Stack *stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack) {
    if (stack->top == -1) {
        return -1;
    }
    return stack->arr[stack->top];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to move elements from stack1 to stack2 while keeping stack2 sorted
void moveSorted(Stack *stack1, Stack *stack2) {
    Stack tempStack;
    tempStack.top = -1;

    while (!isEmpty(stack1)) {
        int current = pop(stack1);

        // Move elements from stack2 to tempStack until correct position is found
        while (!isEmpty(stack2) && peek(stack2) > current) {
            push(&tempStack, pop(stack2));
        }

        // Push the current element into stack2
        push(stack2, current);

        // Move elements back from tempStack to stack2
        while (!isEmpty(&tempStack)) {
            push(stack2, pop(&tempStack));
        }
    }
}

// Function to print a stack
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Stack stack1, stack2;
    stack1.top = -1;
    stack2.top = -1;

    int choice, value;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push to stack1\n");
        printf("2. Move sorted elements to stack2\n");
        printf("3. Display stack1\n");
        printf("4. Display stack2\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push to stack1: ");
                scanf("%d", &value);
                push(&stack1, value);
                break;

            case 2:
                moveSorted(&stack1, &stack2);
                printf("Elements moved to stack2 (sorted).\n");
                break;

            case 3:
                printf("Stack1: ");
                printStack(&stack1);
                break;

            case 4:
                printf("Stack2: ");
                printStack(&stack2);
                break;

            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
