// Fibonacci Series
#include <stdio.h>

int fun(int n, int a, int b)
{
    if (n == 0)
        return a;
    if (n == 1)
        return a;
    return fun(n - 1, b, a + b);
}

int main()
{
    int a, b, n, res;
    printf("n, a, b:\n");
    scanf("%d%d%d", &n, &a, &b);
    res = fun(n, a, b);

    printf("Res = %d\n", res);
    return 0;
}