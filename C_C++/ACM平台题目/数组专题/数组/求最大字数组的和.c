#include <stdio.h>

int main(void)
{
    int i, j, k, z = 0, max = 0;

    int a[8], b[28];//������������


    for (i = 0; i < 8; i++)
        scanf("%d", &a[i]);//��������

    for (i = 0; i < 8; i++)//�������ֶεĺͣ�����������b
        for (k = i + 1; k < 8; k++)
        {
            b[z] = a[i];
            for (j = i + 1; j <= k; j++)
                b[z] += a[j];
            if (max < b[z])
                max = b[z];
            z++;
        }

    printf("%d\n", max);//���b�����е����һλ����

    return 0;
}
