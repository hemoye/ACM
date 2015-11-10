#include <stdio.h>
int main(void)
{
    char str[100];
    int i;

    gets(str);

    for (i = 0; i < strlen(str); i++)
        str[i] += 4;

    printf("password is %s\n", str);

    return 0;
}
