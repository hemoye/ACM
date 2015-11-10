#include <stdio.h>
#include <string.h>

int main(void)
{
    int zhishu(int m);

    int i, n, x, flage;

    while (scanf("%d", &n) != EOF)
    {
        n = pow(10, n-1);

        for (i = n + 1; i < 10 * n; i++)
        {
            if (1 == i / n || 4 == i / n || 6 == i / n || 8 == i / n || 9 == i / n)
                continue;
            x = i;
            flage = 1;
            while (x && flage)
            {
                flage = zhishu(x);
                x /= 10;
            }
            if (0 == x)
                printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}
int zhishu(int m)//定义函数
//功能：判断一个数是不是质数
{
    int i;

    for (i = 2; i <= sqrt(m); i++)
        if (m % i == 0)
            return 0;

    return 1;//是则返回1

}
