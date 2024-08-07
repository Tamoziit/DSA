#include <stdio.h>
#include <stdlib.h>

typedef struct sparseMat
{
    int x;
    int row;
    int col;
} nzEle;

int **add(nzEle *sparr1, nzEle *sparr2)
{
    int flag1 = 0, flag2 = 0;
    int i, j, k;
    int **res = (int **)malloc(sparr1[0].row * sizeof(int *));
    for (i = 0; i < sparr1[0].row; i++)
    {
        res[i] = (int *)malloc(sparr1[0].col * sizeof(int));
    }

    if (sparr1[0].row == sparr2[0].row && sparr1[0].col == sparr2[0].col)
    {
        for (i = 0; i < sparr1[0].row; i++)
        {
            for (j = 0; j < sparr1[0].col; j++)
            {
                flag1 = flag2 = 0;
                for (k = 1; k <= sparr1[0].x; k++)
                {
                    if (sparr1[k].row == i && sparr1[k].col == j)
                        flag1 = k;
                }
                for (k = 1; k <= sparr2[0].x; k++)
                {
                    if (sparr2[k].row == i && sparr2[k].col == j)
                        flag2 = k;
                }

                if (flag1 != 0 && flag2 != 0)
                {
                    res[i][j] = sparr1[flag1].x + sparr2[flag2].x;
                }
                else if (flag1 != 0)
                {
                    res[i][j] = sparr1[flag1].x;
                }
                else if (flag2 != 0)
                {
                    res[i][j] = sparr2[flag2].x;
                }
                else
                {
                    res[i][j] = 0;
                }
            }
        }
    }
    else
    {
        printf("Addition not possible\n");
        exit(0);
    }
    return res;
}

void display(nzEle *sparr, int row, int col)
{
    int i, j, k = 1;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (k <= sparr[0].x && sparr[k].row == i && sparr[k].col == j)
            {
                printf("%d ", sparr[k].x);
                k++;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    int row1, row2, col1, col2, nzcount1, nzcount2;
    printf("Enter no. of rows & cols. for array 1\n");
    scanf("%d%d", &row1, &col1);
    printf("Enter no. of non-zero elements for array 1\n");
    scanf("%d", &nzcount1);
    printf("Enter no. of rows & cols. for array 2\n");
    scanf("%d%d", &row2, &col2);
    printf("Enter no. of non-zero elements for array 2\n");
    scanf("%d", &nzcount2);

    nzEle *p1 = (nzEle *)malloc((nzcount1 + 1) * sizeof(nzEle));
    p1[0].x = nzcount1;
    p1[0].row = row1;
    p1[0].col = col1;
    nzEle *p2 = (nzEle *)malloc((nzcount2 + 1) * sizeof(nzEle));
    p2[0].x = nzcount2;
    p2[0].row = row2;
    p2[0].col = col2;

    int i, j, k;
    printf("For Array 1\n");
    for (k = 1; k <= nzcount1; k++)
    {
        printf("Enter value & indexes of %d no. Non-zero element\n", k);
        scanf("%d", &p1[k].x);
        scanf("%d", &p1[k].row);
        scanf("%d", &p1[k].col);
    }
    printf("For Array 2\n");
    for (k = 1; k <= nzcount2; k++)
    {
        printf("Enter value & indexes of %d no. Non-zero element\n", k);
        scanf("%d", &p2[k].x);
        scanf("%d", &p2[k].row);
        scanf("%d", &p2[k].col);
    }
    printf("\n");
    display(p1, row1, col1);
    printf("\n");
    display(p2, row2, col2);
    printf("\n");

    int **res = add(p1, p2);

    printf("Resultant Matrix:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (i = 0; i < row1; i++)
    {
        free(res[i]);
    }
    free(res);
    free(p1);
    free(p2);

    return 0;
}
