#include <stdio.h>

int main(void)
{
    int n;
    int num_oushu = 0, num_jishu = 0;
    int sum_oushu = 0, sum_jishu = 0;
    sum_jishu = 0;

    while (scanf("%d", &n) && n != 0)
    {
        if (0 == n % 2)
        {
            num_oushu++;
            sum_oushu += n;
        }
        else
        {
            num_jishu++;
            sum_jishu += n;
        }
    }
    printf("num = %d sum = %d\n", num_oushu, sum_oushu / num_oushu);
    printf("num = %d sum = %d\n", num_jishu, sum_jishu / num_jishu);

    return 0;
}
