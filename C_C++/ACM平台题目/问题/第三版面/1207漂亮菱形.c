#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, i, j;

    while (scanf("%d", &n) && n != 0)
    {
        n /= 2;
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j < n - i; j++)
                printf(" ");
            for (j = 0; j < 2 * i + 1; j++)
                printf("*");
            printf("\n");
        }
        for (i = n; i >= 0; i--)
        {
            for (j = n - i; j >= 0; j--)
                printf(" ");
            for (j = 2 * i; j > 1; j--)
                printf("*");
            printf("\n");
        }
    }

    return 0;
}
