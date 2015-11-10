#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000];
    int i, j;

    while (gets(str) != NULL)
    {
        putchar(str[strlen(str) - 1]);
        for (i = 0; i < strlen(str) - 1; i++)
            str[i] = str[i] + 3;
        for (i = 0; i < strlen(str) - 1; i++)
            putchar(str[i]);
        putchar('\n');
    }

    return 0;
}
