#include <stdio.h>
#include <string.h>

int main(void)
{
    int x = 0, y = 0, z = 0, i = 0, time = 0;
    char str[1000], zimu[1000], shuzi[1000], qita[1000];

    while (gets(str) != NULL)
    {
        x = y = z = 0;
        printf("Case #%d:\n", ++time);
        for (i = 0; i < strlen(str); i++)
            if (str[i] >= '0' && str[i] <= '9')
                shuzi[x++] = str[i];
            else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
                zimu[y++] = str[i];
            else
                qita[z++] = str[i];

        for (i = 0; i < y; i++)
            putchar(zimu[i]);
        putchar('\n');
        for (i = 0; i < x; i++)
            putchar(shuzi[i]);
        putchar('\n');
        for (i = 0; i < z; i++)
            putchar(qita[i]);

        putchar('\n');
    }

    return 0;
}
