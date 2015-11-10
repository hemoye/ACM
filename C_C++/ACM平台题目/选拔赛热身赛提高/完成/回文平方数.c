#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d", &m);
    for (n = 1; n <= 300; n++)
    {
        int a[1000] = {0};
        int i, j, x = 0, flage = 1;//定义声明

        i = n * n;
        while (i)
        {
            a[x++] = i % 10;//数组接收i的每一个数字
            i /= 10;
        }

        for (i = 0; i < x; i++)
            while (a[i] >= m)//进制转化，十进制转化成m进制
            {
                a[i] -= m;
                a[i+1] += 1;
            }

        (a[x]) ? (j = x) : (j = x - 1);//判断最高为是否为0，并计算实用数组长度

        for (i = 0; j >= 0; i++, j--)//判断数字是否是回文数
            if (a[i] != a[j])//如果逆序和正序不一样
            {
                flage = 0;//则令标志为0
                break;
            }

        if(flage)//如果标志不为0，则输出结果
        {
            printf("%d ", n);
            if (a[x])//判断最高位是否为0，如果不是0则输出
                printf("%d", a[x]);
            for (i = x - 1; i >= 0; i--)//输出数字
                printf("%d", a[i]);
            printf("\n");
        }
    }

    return 0;
}
