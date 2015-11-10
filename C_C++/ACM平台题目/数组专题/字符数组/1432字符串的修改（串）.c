#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1001], ch[1001], c[10001];
    int i, j, z, x = 0;

    scanf("%s%s%s", str, ch, c);
    for (i = 0; i < strlen(str); i++)
    {
        int flage = 1;
        for (j = 0, z = i; j < strlen(ch); j++)
            if (str[z++] != ch[j])
                flage = 0;
        if (flage)
        {
            for (j = 0; j < strlen(c); j++)
                str[i++] = c[j];
            --i;
            x++;
        }
    }
    if (x)
       puts(str);
    else
       puts("NO");

    return 0;
}
