#include <stdio.h>
#include <stdlib.h>

int lowerTriangle(int **arr, int m, int n)
{
    int i, j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(j<i && arr[i][j] != 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    int m, n, i, j;
    printf("Enter row & cols.\n");
    scanf("%d%d", &m, &n);
    int **arr = (int**)malloc(m*sizeof(int*));
    for(i=0; i<n; i++)
        arr[i] = (int*)malloc(n*sizeof(int));

    printf("Populate the matrix\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            scanf("%d", &arr[i][j]);
    }

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    int res = lowerTriangle(arr, m, n);
    if(res)
        printf("Lower Triangular Matrix\n");
    else
        printf("Not a Lower Triangular Matrix\n");

    for(i=0; i<n; i++)
        free(arr[i]);
    free(arr);
    return 0; 
}