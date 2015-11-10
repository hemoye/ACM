#include <stdio.h>

int main(void)
{
    int m, n, i, j;
    int sum_oushu, sum_jishu;

    while (scanf("%d %d", &m, &n) != EOF)
    {
        sum_oushu = sum_jishu = 0;
        for (i = m; i <= n; i++)
            if (0 == i % 2)
                sum_oushu += i * i;
            else
                sum_jishu += i * i * i;
        printf("%d %d\n", sum_oushu, sum_jishu);
    }

    return 0;
}
