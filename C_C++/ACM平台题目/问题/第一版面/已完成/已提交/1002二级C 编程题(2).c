#include <stdio.h>
int main(void)
{
    double fact(unsigned n);//函数声明
    double mypow(double x, unsigned n);//函数声明

    unsigned n;
    float x;
    int i;//声明语句
    double sum = 0;//声明并赋值语句
    float a, b, c = 1;//声明并赋值语句

    scanf("%f %u", &x, &n);//从键盘输入两个正数

    for (i = 1; i <= n; i++)//控制循环
    {
        a = fact(i);
        b = mypow(x, i);
        sum += (c * (float)(b)) / (float)(a);//x - x2/2! + x3/3! + ... + (-1)n-1xn/n!
        c *= (-1);
    }

    printf("%.4lf\n", sum);
}

double fact(unsigned n)
{
    int i;
    double s = 1;

    for (i = 1; i <= n; i++)
        s *= i;

    return s;
}

double mypow(double x, unsigned n)
{
    int i;
    double k = 1;

    for (i = 1; i <= n; i++)
        k *= x;

    return k;
}
