#include <stdio.h>
int main(void)
{
    int i, j, t, a[10];

    for (i = 0; i < 10; i++)//��������
        scanf("%d", &a[i]);

    for (i = 0; i < 10; i++)   //ð�ݷ�����
        for (j = 0; j < 9; j++)
            if (a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }

    for (i = 0; i < 10; i++)//�������
        printf("%d ", a[i]);
    printf("\n");
}
