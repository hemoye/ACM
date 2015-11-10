#include <stdio.h>

int main(void)
{
    int i, j, n, x, t = 0;

    while (scanf("%d", &n) != EOF)
    {
        int a[1000] = {0};
        for (i = 2; i <= n; i++)
        {
            x = i;
            for (j = 2; x != 1; j++)
                if (x % j == 0)
                {
                    a[j]++;
                    x /= j;
                    j = 1;
                }
        }
        printf("Case %d:\n", ++t);
        printf("%d", 2);
        if (a[2] > 1)
            printf("^%d", a[2]);
        for (i = 3; i < 1000; i++)
            if (a[i] == 1)
                printf("*%d", i);
            else if (a[i] > 1)
                printf("*%d^%d", i, a[i]);
        printf("\n");
    }

    return 0;
}
