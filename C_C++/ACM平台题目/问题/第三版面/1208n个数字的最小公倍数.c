#include <stdio.h>

int main(void)
{
    unsigned Leap_min(unsigned , unsigned );//��������

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
unsigned Leap_min(unsigned m, unsigned n)//���庯��������ֵ����С������
{
    unsigned i, t, sum;

    if (n > m)//����ֵ�Ĵ�ֵ����m��Сֵ����n
    {
        t = n;
        n = m;
        m = t;
    }

    sum = m * n;//���m��n�Ļ�

    while (m % n)//շת����������Լ��
    {
        t = m % n;
        m = n;
        n = t;
    }

    return sum / t;//������С������
}
