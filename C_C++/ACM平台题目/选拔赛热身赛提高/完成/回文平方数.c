#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d", &m);
    for (n = 1; n <= 300; n++)
    {
        int a[1000] = {0};
        int i, j, x = 0, flage = 1;//��������

        i = n * n;
        while (i)
        {
            a[x++] = i % 10;//�������i��ÿһ������
            i /= 10;
        }

        for (i = 0; i < x; i++)
            while (a[i] >= m)//����ת����ʮ����ת����m����
            {
                a[i] -= m;
                a[i+1] += 1;
            }

        (a[x]) ? (j = x) : (j = x - 1);//�ж����Ϊ�Ƿ�Ϊ0��������ʵ�����鳤��

        for (i = 0; j >= 0; i++, j--)//�ж������Ƿ��ǻ�����
            if (a[i] != a[j])//������������һ��
            {
                flage = 0;//�����־Ϊ0
                break;
            }

        if(flage)//�����־��Ϊ0����������
        {
            printf("%d ", n);
            if (a[x])//�ж����λ�Ƿ�Ϊ0���������0�����
                printf("%d", a[x]);
            for (i = x - 1; i >= 0; i--)//�������
                printf("%d", a[i]);
            printf("\n");
        }
    }

    return 0;
}
