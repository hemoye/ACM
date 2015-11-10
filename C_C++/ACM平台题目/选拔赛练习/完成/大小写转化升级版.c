#include <stdio.h>
#include <string.h>

int main(void)
{
    int cas, t, i;
    char str[1001];

    scanf("%d", &cas);

    str[0] = getchar();

    for (t = 1,i = 0; t <= cas; t++)
    {
        gets(str);
        printf("Case %d:\n", t);

        for (; i < strlen(str); i++)
        {
            if (i % 2 == 0)
            {
                if (str[i] >= 'A' && str[i] <= 'Z')
                    str[i] += 32;
            }
            else
            {
                if (str[i] >= 'a' && str[i] <= 'z')
                    str[i] -= 32;
            }
            putchar(str[i]);
        }
        printf("\n");
    }

    return 0;
}
