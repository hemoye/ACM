#include <stdio.h>

int main(void)
{
    int n, t, i, j, temp, a[1000];//声明语句

    scanf("%d", &n);//输入测试数据的组数

    for (t = 1; t <= n; t++)
    {
        for (i = 5; i < 11; i++)//从下标5开始输入数组
            scanf("%d", &a[i]);
        printf("Case %d:\n", t);
        for (i = 5; i < 11; i++)//输出第一行
            printf((5 == i) ? "%d" : " %d", a[i]);
        printf("\n");
        for (i = 10, temp = 4; i > 5; temp--, i--)
        {
            a[temp] = a[i];//每一次循环之后都把最后一个元素放到最前面
            for (j = temp; j < temp + 6; j++)
                printf((j == temp) ? "%d" : " %d", a[j]);
            printf("\n");
        }
    }

    return 0;
}
