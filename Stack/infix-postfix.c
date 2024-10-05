#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
    for (i = l - 1; i >= 0; i--)
    {
        printf("%c ", sptr->dataStk[i]);
    }
    printf("\n");
}

void printFloatStack(eStack *sptr, int l)
{
    int i;
    for (i = l - 1; i >= 0; i--)
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

char *infixToPostfix(char *infix, Stack *sptr)
{
    int len = strlen(infix);
    char c, top, x;
    int i, l = 0;
    char *postfix = (char *)malloc(len * sizeof(char));
    int j = 0;
    sptr->top = -1;

    for (i = 0; i < len; i++)
    {
        c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        { // operand
            postfix[j] = c;
            j++;
        }

        else if (c == '(') // bracket case handling
        {
            push(sptr, c);
            l++;
        }

        else if (c == ')') // bracket case resolution
        {
            while (!emptyStack(sptr) && (top = pop(sptr)) != '(')
            {
                postfix[j] = top;
                j++;
            }
            if (top != '(')
            {
                printf("Erronous Infix Exp\n");
                return NULL;
            }
        }

        else // operator
        {
            while (!emptyStack(sptr))
            {
                top = pop(sptr);
                l--;
                if ((precedence(c) < precedence(top)) || (precedence(c) == precedence(top) && associativity(top) == 'L'))
                {
                    postfix[j] = top;
                    j++;
                }
                else
                {
                    push(sptr, top);
                    l++;
                    break;
                }
            }
            push(sptr, c);
            l++;
        }

        printCharStack(sptr, l);
    }

    while (!emptyStack(sptr))
    {
        x = pop(sptr);
        l--;
        postfix[j] = x;
        j++;
        printCharStack(sptr, l);
    }

    postfix[j] = '\0';
    return postfix;
}

float postfixEvaluator(eStack *sptr, char *postfix)
{
    int i = 0, l = 0;
    float op1, op2, x, res = 0.0;
    char c;

    while ((c = postfix[i]) != '\0')
    {
        if (c != '+' && c != '-' && c != '*' && c != '/' && c != '^')
        {
            x = c - '0';
            ePush(sptr, x);
            l++;
        }
        else
        {
            op2 = ePop(sptr);
            op1 = ePop(sptr);
            l -= 2;

            switch (c)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '^':
                res = pow(op1, op2);
                break;
            default:
                printf("Operator not listed\n");
                exit(0);
            }

            ePush(sptr, res);
            l++;
        }
        i++;
        printFloatStack(sptr, l);
    }

    return res;
}

int main()
{
    int n;
    printf("Enter the length of postfix exp.\n");
    scanf("%d", &n);
    char *infix = (char *)malloc(n * sizeof(char));
    printf("Enter the infix exp.\n");
    scanf("%s", infix);
    printf("Infix exp. = %s\n", infix);

    // Stack objects
    Stack s;
    s.capacity = n;
    s.dataStk = (char *)malloc(s.capacity * sizeof(char));
    eStack sp;
    sp.capacity = n;
    sp.dataStk = (float *)malloc(sp.capacity * sizeof(float));

    char *postfix = NULL;
    postfix = infixToPostfix(infix, &s);
    if (postfix != NULL)
    {
        printf("Postfix exp. = %s\n", postfix);
    }

    float res = postfixEvaluator(&sp, postfix);
    printf("Result = %f\n", res);

    return 0;
}