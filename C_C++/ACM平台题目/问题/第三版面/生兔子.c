#include <stdio.h>

int yangtuzi(int );//��������

int main(void)//������
{
    int i, day;//�������

    while (scanf("%d", &day) != EOF)//�������ڣ���������Ϊ0��ʱ����ֹѭ��
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
