#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    int i;

    gets(str);
    for (i = strlen(str) - 1; i >= 0; i--)
        putchar(str[i]);
    printf("\n");

    return 0;
}
