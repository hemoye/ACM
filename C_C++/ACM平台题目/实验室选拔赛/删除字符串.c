#include <stdio.h>

int main(void)
{
    int i, j, z, num, t = 0;
    char str[151], ch[151];

    while (scanf("%s%s", str, ch) != EOF)
    {
        num = 0;
        if (strcmp (str, "#") == 0 && strcmp (ch, "#") == 0)
            break;
        printf("Case %d:\n", ++t);

        for (i = 0; i < strlen(str); i++)
        {
            int flage = 1;
            for (j = 0, z = i; j < strlen(ch); j++)
                if (str[z++] != ch[j])
                {
                    flage = 0;
                    break;
                }
            if (flage)
            {
                num++;
                for ( ; i < strlen(str) - strlen(ch); i++)
                    str[i] = str[i+strlen(ch)];
                str[i] = '\0';
                i = -1;
            }
        }
        printf("%s\n%d\n", str, num);
    }

    return 0;
}
