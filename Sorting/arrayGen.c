#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Creating input file with random data */
int main()
{
    srand(time(NULL));
    int r, x, y, i, size;
    FILE *f1;
    f1 = fopen("C:\\Users\\Tamojit\\Desktop\\DSA\\sorting\\input.txt", "w");
    if (f1 != NULL)
    {
        printf("Enter range\n");
        scanf("%d%d", &x, &y);
        printf("Enter size\n");
        scanf("%d", &size);
        fprintf(f1, "%d\n", size);

        for (i = 0; i < size; i++)
        {
            r = x + rand() % (y - x);
            fprintf(f1, "%d\n", r);
        }
        fclose(f1);
        printf("Input file created successfully\n");
    }
    else
    {
        printf("Error in creating Input file\n");
    }

    return 0;
}
