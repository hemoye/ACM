#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1001];
    int i;

    gets(str);
    for (i = 2; i < strlen(str); i++)
        printf("%c", str[i]);
    printf("%c%c\n", str[0], str[1]);

    return 0;
}
