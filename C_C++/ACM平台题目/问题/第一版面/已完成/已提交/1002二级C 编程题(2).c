#include <stdio.h>
int main(void)
{
    double fact(unsigned n);//��������
    double mypow(double x, unsigned n);//��������

    unsigned n;
    float x;
    int i;//�������
    double sum = 0;//��������ֵ���
    float a, b, c = 1;//��������ֵ���

    scanf("%f %u", &x, &n);//�Ӽ���������������

    for (i = 1; i <= n; i++)//����ѭ��
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
