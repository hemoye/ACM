#include <stdio.h>

int main(void)
{
    int n, t, i, j, temp, a[1000];//�������

    scanf("%d", &n);//����������ݵ�����

    for (t = 1; t <= n; t++)
    {
        for (i = 5; i < 11; i++)//���±�5��ʼ��������
            scanf("%d", &a[i]);
        printf("Case %d:\n", t);
        for (i = 5; i < 11; i++)//�����һ��
            printf((5 == i) ? "%d" : " %d", a[i]);
        printf("\n");
        for (i = 10, temp = 4; i > 5; temp--, i--)
        {
            a[temp] = a[i];//ÿһ��ѭ��֮�󶼰����һ��Ԫ�طŵ���ǰ��
            for (j = temp; j < temp + 6; j++)
                printf((j == temp) ? "%d" : " %d", a[j]);
            printf("\n");
        }
    }

    return 0;
}
