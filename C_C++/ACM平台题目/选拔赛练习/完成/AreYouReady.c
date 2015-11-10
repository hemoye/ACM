#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, t, i;
    char str[1001];

    scanf("%d", &n);
    for (t = 1; t <= n; t++)
    {
        str[0] = getchar();
        gets(str);

        printf("Case %d:\n", t);

        for (i = 0; i < strlen(str); i++)
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
                putchar(str[i]);
        printf("\n");
    }

    return 0;
}
