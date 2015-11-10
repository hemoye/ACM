#include <stdio.h>
int main(void)
{
    int i, j, n, m, x, sum;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (m = 1; m < 2 * (n - i) - 1; m++)
            printf(" ");
        sum = x = 0;
        for (j = 1; j <= 2 * i + 1; j++)
        {
            sum += 1;
            if (sum <= i + 1)
                printf("%d ", sum);
            else
            {
                x += 2;
                printf("%d ", sum - x);
            }
        }
        printf("\n");
    }

    return 0;
}
