#include <stdio.h>
#include <stdlib.h>

struct term
{
    int cx;
    int cy;
    int ex;
    int ey;
};

typedef struct term Term;

void add(Term x, Term y)
{
    int resx = -99999, resy = -99999; // Initialize with sentinel values
    int ex_res = -99999, ey_res = -99999;

    // If the exponents of x are equal
    if (x.ex == y.ex)
    {
        resx = x.cx + y.cx;
        ex_res = x.ex;
    }

    // If the exponents of y are equal
    if (x.ey == y.ey)
    {
        resy = x.cy + y.cy;
        ey_res = x.ey;
    }

    // Handling different cases for the addition
    if (resx != -99999 && resy != -99999)
    {
        if (resy >= 0)
            printf("Result = %dx^%d + %dy^%d\n", resx, ex_res, resy, ey_res);
        else
            printf("Result = %dx^%d %dy^%d\n", resx, ex_res, resy, ey_res);
    }
    else if (resx != -99999)
    {
        if (x.cy >= 0 && y.cy >= 0)
            printf("Result = %dx^%d + %dy^%d + %dy^%d\n", resx, ex_res, x.cy, x.ey, y.cy, y.ey);
        else if (x.cy >= 0)
            printf("Result = %dx^%d + %dy^%d %dy^%d\n", resx, ex_res, x.cy, x.ey, y.cy, y.ey);
        else
            printf("Result = %dx^%d %dy^%d + %dy^%d\n", resx, ex_res, x.cy, x.ey, y.cy, y.ey);
    }
    else if (resy != -99999)
    {
        if (x.cx >= 0 && y.cx >= 0)
            printf("Result = %dx^%d + %dx^%d + %dy^%d\n", x.cx, x.ex, y.cx, y.ex, resy, ey_res);
        else if (x.cx >= 0)
            printf("Result = %dx^%d + %dx^%d %dy^%d\n", x.cx, x.ex, y.cx, y.ex, resy, ey_res);
        else
            printf("Result = %dx^%d %dx^%d + %dy^%d\n", x.cx, x.ex, y.cx, y.ex, resy, ey_res);
    }
    else
    {
        if (x.cx >= 0 && x.cy >= 0 && y.cx >= 0 && y.cy >= 0)
            printf("Result = %dx^%d + %dy^%d + %dx^%d + %dy^%d\n", x.cx, x.ex, x.cy, x.ey, y.cx, y.ex, y.cy, y.ey);
        else if (x.cx >= 0 && x.cy >= 0 && y.cx >= 0)
            printf("Result = %dx^%d + %dy^%d + %dx^%d %dy^%d\n", x.cx, x.ex, x.cy, x.ey, y.cx, y.ex, y.cy, y.ey);
        else if (x.cx >= 0 && x.cy >= 0 && y.cy >= 0)
            printf("Result = %dx^%d + %dy^%d %dx^%d + %dy^%d\n", x.cx, x.ex, x.cy, x.ey, y.cx, y.ex, y.cy, y.ey);
        else if (x.cx >= 0 && y.cx >= 0 && y.cy >= 0)
            printf("Result = %dx^%d %dy^%d + %dx^%d + %dy^%d\n", x.cx, x.ex, x.cy, x.ey, y.cx, y.ex, y.cy, y.ey);
        else if (x.cy >= 0 && y.cx >= 0 && y.cy >= 0)
            printf("Result = %dx^%d + %dy^%d %dx^%d + %dy^%d\n", x.cx, x.ex, x.cy, x.ey, y.cx, y.ex, y.cy, y.ey);
        else if (x.cx >= 0 && y.cx >= 0)
            printf("Result = %dx^%d %dy^%d + %dx^%d %dy^%d\n", x.cx, x.ex, x.cy, x.ey, y.cx, y.ex, y.cy, y.ey);
        else if (x.cx >= 0 && y.cy >= 0)
            printf("Result = %dx^%d %dy^%d + %dx^%d %dy^%d\n", x.cx, x.ex, x.cy, x.ey, y.cx, y.ex, y.cy, y.ey);
        else if (x.cy >= 0 && y.cx >= 0)
            printf("Result = %dx^%d + %dy^%d %dx^%d %dy^%d\n", x.cx, x.ex, x.cy, x.ey, y.cx, y.ex, y.cy, y.ey);
        else
            printf("Result = %dx^%d %dy^%d %dx^%d %dy^%d\n", x.cx, x.ex, x.cy, x.ey, y.cx, y.ex, y.cy, y.ey);
    }
}

void multiply(Term x, Term y)
{
    int t1, t2, t3, t4;
    ;
    int ex_res, ey_res;
    t1 = x.cx * y.cx;
    t2 = x.cx * y.cy;
    t3 = x.cy * y.cx;
    t4 = x.cy * y.cy;
    ex_res = x.ex + y.ex;
    ey_res = x.ey + y.ey;
    printf("Result 2 = %dx^%d %dx^%d.y^%d %dx^%d.y^%d %dy^%d\n", t1, ex_res, t2, x.ex, y.ey, t3, x.ex, y.ey, t4, ey_res);
}

int main()
{
    Term x, y;
    printf("Enter first term (cx ex cy ey): \n");
    scanf("%d %d %d %d", &x.cx, &x.ex, &x.cy, &x.ey);

    printf("Enter second term (cx ex cy ey): \n");
    scanf("%d %d %d %d", &y.cx, &y.ex, &y.cy, &y.ey);

    add(x, y);
    multiply(x, y);
    return 0;
}