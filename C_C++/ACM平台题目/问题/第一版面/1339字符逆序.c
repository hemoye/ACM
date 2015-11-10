#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    char str[101];

    gets(str);
    for (i = strlen(str) - 1; i >= 0; i--)
        putchar(str[i]);
    puts("");

    return 0;
}
