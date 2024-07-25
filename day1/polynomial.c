#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial
{
    int c;
    int ex;
    int ey;
} Term;

int k;

Term *sort(Term *p, int n)
{
    int i, j;
    Term t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if ((p[j].ex > p[j + 1].ex) || (p[j].ex == p[j + 1].ex && p[j].ey > p[j + 1].ey))
            {
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }
    return p;
}

Term *add(Term *p1, Term *p2, int n1, int n2)
{
    int i, j;
    k = 0;
    Term *res = (Term *)malloc((n1 + n2) * sizeof(Term));
    for (i = 0, j = 0, k = 0; i < n1 && j < n2;)
    {
        if ((p1[i].ex == p2[j].ex) && (p1[i].ey == p2[j].ey))
        {
            if (p1[i].c + p2[i].c != 0)
            {
                res[k].c = p1[i].c + p2[i].c;
                res[k].ex = p1[i].ex;
                res[k].ey = p2[j].ey;
                k++;
            }
            i++;
            j++;
        }
        else
        {
            if ((p1[i].ex < p2[j].ex) || (p1[i].ex == p2[j].ex && p1[i].ey < p2[j].ey))
            {
                res[k] = p1[i];
                i++;
                k++;
            }
            else
            {
                res[k] = p2[j];
                j++;
                k++;
            }
        }
    }
    if (i < n1)
    {
        while (i < n1)
        {
            res[k] = p1[i];
            i++;
            k++;
        }
    }
    else if (j < n2)
    {
        while (j < n2)
        {
            res[k] = p2[j];
            j++;
            k++;
        }
    }
    return res;
}

int main()
{
    int n1, n2, i;
    printf("Enter Sizes\n");
    scanf("%d%d", &n1, &n2);
    Term *p1 = (Term *)malloc(n1 * sizeof(Term));
    Term *p2 = (Term *)malloc(n2 * sizeof(Term));
    printf("Enter the terms of 1st polynomial\n");
    for (i = 0; i < n1; i++)
    {
        printf("Term %d:\n", (i + 1));
        scanf("%d%d%d", &p1[i].c, &p1[i].ex, &p1[i].ey);
    }
    printf("Enter the terms of 2nd polynomial\n");
    for (i = 0; i < n2; i++)
    {
        printf("Term %d:\n", (i + 1));
        scanf("%d%d%d", &p2[i].c, &p2[i].ex, &p2[i].ey);
    }

    p1 = sort(p1, n1);
    p2 = sort(p2, n2);

    Term *res = (Term *)malloc(k * sizeof(Term));
    res = add(p1, p2, n1, n2);
    printf("Result : \n");
    for (i = 0; i < k; i++)
    {
        if (i != k - 1)
            printf("(%d)x^%d.y^%d + ", res[i].c, res[i].ex, res[i].ey);
        else
            printf("(%d)x^%d.y^%d\n", res[i].c, res[i].ex, res[i].ey);
    }

    free(p1);
    free(p2);
    free(res);
    return 0;
}