#include <stdio.h>
int main(void)
{
    int m, n, i, j, a;

    scanf ("%d", &n);
    for (m = 0; m < n; m++)
    {
        scanf ("%d", &a);
        for (i = 0; i < a; i++)
        {
            for (j = 0; j <= i; j++)
                printf("*");
            printf("\n");
        }
    }

    return 0;
}
