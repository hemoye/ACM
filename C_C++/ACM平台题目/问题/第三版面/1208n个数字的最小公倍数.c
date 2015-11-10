#include <stdio.h>

int main(void)
{
    unsigned Leap_min(unsigned , unsigned );//函数声明

    unsigned n;
    while (scanf("%u", &n) != EOF)
    {
        unsigned a[n];
        int i;

        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n - 1; i++)
            a[i+1] = Leap_min(a[i], a[i+1]);
        printf("%u\n", a[i]);
    }

    return 0;
}
unsigned Leap_min(unsigned m, unsigned n)//定义函数求两个值的最小公倍数
{
    unsigned i, t, sum;

    if (n > m)//把两值的大值放在m，小值放在n
    {
        t = n;
        n = m;
        m = t;
    }

    sum = m * n;//求得m，n的积

    while (m % n)//辗转相除法求最大公约数
    {
        t = m % n;
        m = n;
        n = t;
    }

    return sum / t;//返回最小公倍数
}
