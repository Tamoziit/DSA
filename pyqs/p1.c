#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct stack
{
    int top;
    int capacity;
    char *dataStk;
} Stack;

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

int emptyStack(Stack *sptr)
{
    if (sptr->top == -1)
        return 1;
    else
        return 0;
}

void validParenthesis(Stack *sptr, char *s)
{
    sptr->top = -1;
    char c, top;
    int i = 0, l = strlen(s);
    int p = 0;

    while (i < l)
    {
        c = s[i];
        if (c == '(' || c == '{' || c == '[')
        {
            push(sptr, c);
            p++;
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (!emptyStack(sptr))
            {
                top = pop(sptr);
                p--;
            }
            else
            {
                printf("Not a valid parenthesis expression\n");
                return;
            }

            if ((top == '(' && c != ')') || (top == '{' && c != '}') || (top == '[' && c != ']'))
            {
                printf("Not a valid parenthesis expression\n");
                return;
            }
        }

        i++;
    }

    if (p == 0)
        printf("Valid parenthesis expression\n");
    else
        printf("Not a valid parenthesis expression\n");
}

int main()
{
    char *exp = (char *)malloc(MAX * sizeof(char));
    printf("Enter the parenthesis exp.\n");
    scanf("%s", exp);

    Stack stk;
    stk.capacity = MAX;
    stk.dataStk = (char *)malloc(stk.capacity * sizeof(char));

    validParenthesis(&stk, exp);
    free(exp);
    free(stk.dataStk);
    return 0;
}