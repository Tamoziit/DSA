#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int top;
    int capacity;
    char *dataStk;
} Stack;

typedef struct evalStack
{
    int top;
    int capacity;
    float *dataStk;
} eStack;

/* Stack Ops */
void push(Stack *sptr, char c)
{
    if (sptr->top == sptr->capacity)
    {
        printf("Overflow\n");
        exit(0);
    }

    sptr->top++;
    sptr->dataStk[sptr->top] = c;
}

char pop(Stack *sptr)
{
    if (sptr->top == -1)
    {
        printf("Underflow\n");
        exit(0);
    }

    char c = sptr->dataStk[sptr->top];
    sptr->top--;
    return c;
}

void ePush(eStack *sptr, float c)
{
    if (sptr->top == sptr->capacity)
    {
        printf("Overflow\n");
        exit(0);
    }

    sptr->top++;
    sptr->dataStk[sptr->top] = c;
}

float ePop(eStack *sptr)
{
    if (sptr->top == -1)
    {
        printf("Underflow\n");
        exit(0);
    }

    float c = sptr->dataStk[sptr->top];
    sptr->top--;
    return c;
}

int emptyStack(Stack *sptr)
{
    if (sptr->top == -1)
        return 1;
    else
        return 0;
}

void printCharStack(Stack *sptr, int l)
{
    int i;
    for (i = 0; i < l; i++)
    {
        printf("%c ", sptr->dataStk[i]);
    }
    printf("\n");
}

void printFloatStack(eStack *sptr, int l)
{
    int i;
    for (i = 0; i < l; i++)
    {
        printf("%f ", sptr->dataStk[i]);
    }
    printf("\n");
}

/* Infix to Postfix */
int precedence(char c)
{
    if (c == '^')
        return 4;
    if (c == '%')
        return 3;
    if (c == '/' || c == '*')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    if (c == '(')
        return 0;
}

char associativity(char c)
{
    if (c == '^' || c == '%')
        return 'R';
    else
        return 'L';
}