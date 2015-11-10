#include <stdio.h>
#include <string.h>
int main(void)
{
    char str1[100], str2[100];
    int i, j;

    gets(str1);

    for (i = 0, j = strlen(str1) - 1; i < strlen(str1); i++)
    {
        if (str1[i] >= '0' && str1[i] <= '9')
            str2[j--] = '9' - str1[i] + '0';
        else if (str1[i] >= 'a' && str1[i] <= 'z')
            str2[j--] = str1[i] - 32;
        else if (str1[i] >= 'A' && str1[i] <= 'Z')
            str2[j--] = str1[i] + 32;
    }

    for (i = 0; i < strlen(str1); i++)
        putchar(str2[i]);
    putchar('\n');

    return 0;
}
