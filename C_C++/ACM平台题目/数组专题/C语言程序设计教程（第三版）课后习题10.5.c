#include <stdio.h>

int main(void)
{
    int n, k, i, j;//声明语句

    scanf("%d", &n);//获得两个数字
    int a[n];//定义一个长度为n的数组

    for (i = 0; i < n; i++)//用数组从小到大接收1~n
        a[i] = i + 1;
    for (i = n, j = 0; i > 0; i--)
    {
        for (k = 0; k < 3; k++)
            if (++j > i - 1)
                j = 0;

        if (j)
            for (k = --j; k < i - 1; k++)
                a[k] = a[k+1];
    }
    printf("%d\n", a[0]);

    return 0;
}
