#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void returnUnique(char *s, char *res)
{
    int *freq = (int *)malloc(26 * sizeof(int));
    int i, x = 0;
    char ch;
    for (i = 0; i < 26; i++)
        freq[i] = 0;

    for (i = 0; i < strlen(s); i++)
    {
        ch = s[i];
        freq[ch - 'a']++;
    }

    for (i = 0; i < 26; i++)
        printf("%d ", freq[i]);
    printf("\n");

    for (i = 0; i < 26; i++)
    {
        if (freq[i] == 1)
            res[x++] = 'a' + i;
    }
    res[x] = '\0';
    free(freq);
}

int main()
{
    char *s, *res;
    s = (char *)malloc(MAX * sizeof(char));
    res = (char *)malloc(MAX * sizeof(char));
    printf("Enter the sequence\n");
    scanf("%s", s);
    printf("The Sequence: %s\n", s);

    returnUnique(s, res);
    printf("The Unique sequence: %s\n", res);
    free(s);
    free(res);
    return 0;
}