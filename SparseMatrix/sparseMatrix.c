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
    if (sparr1[0].row == sparr2[0].row && sparr1[0].col == sparr2[0].col)
    {
        int res[sparr1[0].row][sparr1[0].col];
        int i, j, k;
        for (i = 0; i < sparr1[0].row; i++)
        {
            for (j = 0; j < sparr1[0].col; i++)
            {
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
                    flag1 = 0;
                    flag2 = 0;
                }
                else if (flag1 != 0)
                {
                    res[i][j] = sparr1[flag1].x;
                    flag1 = 0;
                }
                else if (flag2 != 0)
                {
                    res[i][j] = sparr2[flag2].x;
                    flag2 = 0;
                }
                else
                    res[i][j] = 0;
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