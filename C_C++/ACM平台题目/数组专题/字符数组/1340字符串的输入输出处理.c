#include <stdio.h>
#include <string.h>

int main(void)
{
    unsigned N, n = 0;
    int i, j;
    char str[1001][1001];

    scanf("%d\n", &N);
    while (gets(str[n++]) != NULL);

    for (i = 0; i < N; i++)
    {
        puts(str[i]);
        puts("");
    }
    for ( ; i < n; i++)
    {
        for (j = 0; j < strlen(str[i]); j++)
            if (str[i][j] == ' ')
            {
                puts("");
                puts("");
            }
            else
                printf("%c", str[i][j]);
            puts("");
            puts("");
    }

    return 0;
}
