#include <stdio.h>

int yangtuzi(int );//函数声明

int main(void)//主函数
{
    int i, day;//声明语句

    while (scanf("%d", &day) != EOF)//输入日期，并当日期为0的时候终止循环
    {
        if (0 == day)
            break;

        int sum = 0, a = 1, b = 0;

        for (i = 0; i < day; i++)
        {
            sum = a + b;
            b = a;
            a = sum;
        }
        printf("%d\n", sum);
    }

    return 0;
}
