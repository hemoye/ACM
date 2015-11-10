#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000];
    int z = 0;

    while (gets(str) != NULL)
    {
        int i, j, a[1000] = {0};

        for (i = j = 0; i < strlen(str); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
                a[j] = a[j] * 10 + (str[i] - '0');
            else
                j++;
        }
        for (i = 1; i <= j; i++)
            a[0] += a[i];
        printf("Case #%d:\nsum = %d\n", ++z, a[0]);
    }

    return 0;
}
