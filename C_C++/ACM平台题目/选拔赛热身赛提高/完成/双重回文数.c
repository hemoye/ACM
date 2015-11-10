#include <stdio.h>

int main(void)
{
    int judge(int , int );//函数声明

    int n, m, i, j, num;//声明语句
    scanf("%d %d", &m, &n);//输入第一个数字以及测试数据的长度
    for (i = n + 1; i <= n + m; i++)//从n+1开始测试m个数据
    {
        for (num = 0, j = 2; j <= 10; j++)//循环判断是否是双重以上的回文数
            num += judge(i, j);//函数调用

        if (num >= 2)//如果num能够累加到2以上，则输出被判断数字
           printf("%d\n", i);
    }

    return 0;
}
int judge(int n, int m)//定义函数
//功能：判断一个十进制数字转化成m进制之后是不是回文数
{
    int i, j = 0, a[1000] = {0};//定义声明

    while (n)//用除k取余法求的十进制n的m进制数
    {
        a[j++] = n % m;//数组接收i的每一个数字
        n /= m;
    }

    (a[j]) ? (i = j) : (i = j - 1);//判断最高为是否为0，并计算实用数组长度

    for (j = 0; i >= 0; i--, j++)//判断数字是否是回文数
        if (a[i] != a[j])//如果逆序和正序不一样
            return 0;//则返回0并结束程序

    return 1;//如果上面的for循环能全部完成，则表明n转化成m进制后的数是回文数，则返回1
}
