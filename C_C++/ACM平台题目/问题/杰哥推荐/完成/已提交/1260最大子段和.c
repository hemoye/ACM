#include <stdio.h>

int main(void)
{
    int n, i, j, k;

    while (scanf("%d", &n) && n != 0)
    {
        int a[n], b[(n * (n - 1)) / 2];//������������
        int flage = 0, z = 0;

        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);//��������
        for (i = 0; i < n; i++)
            if (a[i] > 0)
                flage = 1;
        if (flage)
        {
            for (i = 0; i < n; i++)//�������ֶεĺͣ�����������b
                for (k = i + 1; k < n; k++)
                {
                    b[z] = a[i];
                    for (j = i + 1; j <= k; j++)
                        b[z] += a[j];
                    z++;
                }
            for (i = 0; i < z; i++)//ð�ݷ���b��������
                for (j = 0; j < z - i; j++)
                    if (b[j] > b[j+1])
                    {
                        n = b[j];
                        b[j] = b[j+1];
                        b[j+1] = n;
                    }
            printf("%d\n", b[--z]);//���b�����е����һλ����
        }
        else
        printf("0\n");
    }

    return 0;
}
