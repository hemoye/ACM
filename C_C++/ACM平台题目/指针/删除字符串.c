#include <stdio.h>
#include <string.h>

int detele(char * str, char * ch)
{
    int i, j, z;
    int flage = 1;
    for (i = 0; i < strlen(str); i++)
    {
        flage = 1;
        for (z = i, j = 0; j < strlen(ch); j++)
            if (str[z++] != ch[j])
                flage = 0;
        if (flage)
        {
            z = i;
            break;
        }
    }
    if (flage)
    {
        for (i = z; i < strlen(str) - strlen(ch); i++)
            str[i] = str[i+strlen(ch)];
        str[i] = '\0';
        return 1;
    }
    return 0;
}
int main(void)
{
    int T;
    char str[1001], ch[1001];

    scanf("%d", &T);
    while (T--)
    {
        scanf("%s%s", str, ch);
        if (detele(str, ch))
            printf("YES,%s\n", str);
        else
            printf("NO\n");
    }

    return 0;
}
