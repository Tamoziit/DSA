#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int checkPalindrome(char s[], char res[], int n)
{
    static int i = 0;
    
    if (n > 0)
    {
        char ch = s[n - 1];
        res[i++] = ch;
        checkPalindrome(s, res, n - 1);
    }
    else
    {
        res[i] = '\0';
        return strcmp(res, s) == 0;
    }
}

int main()
{
    char *s = (char *)malloc(MAX * sizeof(char));
    char *res = (char *)malloc(MAX * sizeof(char));
    printf("Enter String:\n");
    scanf("%s", s);
    int n = strlen(s);

    if (checkPalindrome(s, res, n))
    {
        printf("Palindrome String\n");
    }
    else
    {
        printf("Not Palindrome String\n");
    }

    printf("Original = %s\n", s);
    printf("Reversed String = %s\n", res);

    free(s);
    free(res);
    return 0;
}