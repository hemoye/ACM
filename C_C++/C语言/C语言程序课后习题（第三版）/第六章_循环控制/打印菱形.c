#include <stdio.h>
int main(void)

{
    int i, j, n, m;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (m = 0; m < n-i; m++)
            printf(" ");
        for (j = 0; j < 2 * i - 1; j++)
            printf("*");
        printf("\n");
    }
    for (i = n; i > 0; i--)
    {
        for (m = n; m > i-1; m--)
            printf(" ");
        for (j = 2 * i - 3; j > 0; j--)
            printf("*");
        printf("\n");
    }

}
