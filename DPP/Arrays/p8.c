// STOCK  PRICES & SPAN
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->data[s->top];
}

// Calculate stock span
void calculateSpan(int prices[], int n, int span[]) {
    Stack s;
    initStack(&s);

    for (int i = 0; i < n; i++) {
        // Pop elements from the stack while the current price is greater than the top of the stack
        while (!isEmpty(&s) && prices[peek(&s)] <= prices[i]) {
            pop(&s);
        }

        // If the stack is empty, span is i + 1; otherwise, span is the difference between indices
        if (isEmpty(&s)) {
            span[i] = i + 1;
        } else {
            span[i] = i - peek(&s);
        }

        // Push the current index onto the stack
        push(&s, i);
    }
}

int main() {
    int n;

    printf("Enter the number of days: ");
    scanf("%d", &n);

    int prices[n], span[n];

    printf("Enter the stock prices:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    calculateSpan(prices, n, span);

    printf("Stock spans are:\n");
    for (int i = 0; i < n; i++) {
        printf("Day %d (Price: %d) -> Span: %d\n", i + 1, prices[i], span[i]);
    }

    return 0;
}