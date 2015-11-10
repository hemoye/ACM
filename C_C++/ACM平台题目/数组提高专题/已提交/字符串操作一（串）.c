#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, n;
    char str[1000], a[1000];

    while (gets(str) != NULL)
    {
        n = strlen(str) / 2;
        j = 0;
        if (strlen(str) % 2 == 0)
        {
            for (i = n - 1; i >= 0; i--)
                a[j++] = str[i];
            for (i = strlen(str) - 1; i >= n; i--)
                a[j++] = str[i];
        }
        else
        {
            for (i = n - 1; i >= 0; i--)
                a[j++] = str[i];
            a[j++] = str[n];
            for (i = strlen(str) - 1; i > n; i--)
                a[j++] = str[i];
        }
        a[j] = '\0';
        puts(a);
    }

    return 0;
}
