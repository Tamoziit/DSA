#include <stdio.h>
#include <stdlib.h>
#define MAXROWS 100

void push(char arr[], char c, int *tail)
{
    if (*tail == MAXROWS - 1)
    {
        printf("Queue full\n");
        return;
    }

    (*tail)++;
    arr[*tail] = c;
}

char pop(char arr[], int *tail)
{
    if (*tail == -1)
    {
        printf("Empty Queue\n");
        return 'a';
    }

    char ch = arr[*tail];
    (*tail)--;
    return ch;
}

int isParenthesesBalanced(char exp[], char stack[], int n)
{
    int tail = -1;
    int i;
    char ch, p;
    for (i = 0; i < n; i++)
    {
        ch = exp[i];
        if (ch == '(')
            push(stack, ch, &tail);
        else if (ch == ')')
        {
            p = pop(stack, &tail);
            if (p != '(')
                return 0;
        }
    }

    if (tail == -1)
        return 1;
    else
        return 0;
}

int main()
{
    char *stack = (char *)malloc(MAXROWS * sizeof(char));
    int n;

    printf("Enter size of exp.\n");
    scanf("%d", &n);
    printf("Enter exp.\n");
    char *exp = (char *)malloc((n + 1) * sizeof(char));
    scanf("%s", exp);

    int res = isParenthesesBalanced(exp, stack, n);
    if (res)
        printf("Valid parenthesis exp.\n");
    else
        printf("Not valid parenthesis statement.\n");

    return 0;
}