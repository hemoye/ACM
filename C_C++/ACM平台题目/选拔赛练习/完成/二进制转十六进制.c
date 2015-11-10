#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1001];
    int i, j, t, num, sum, T;

    scanf("%d", &T);//控制测试数据的组数
    for (t = 1; t <= T; t++)
    {
        scanf("%s", str);//获得二进制数字字符串
        for (i = strlen(str) - 1, j = sum = 0; i >= 0; i--)//逆序累加
        {
            num = 1;//初始化变量
            for (j = 0; j < strlen(str) - 1 - i; j++)
                num *= 2;
            sum += (num * (str[i] - '0'));//二进制转化为十进制
        }
        printf("Case %d: %X\n", t, sum);//十进制数字以二进制的形式输出
    }

    return 0;
}
