#include <stdio.h>
int main(void)
{
    unsigned n;//�������
    int i, j, a[6][6], b[6][6];//�������

    scanf("%u", &n);//�Ӽ�������һ��������

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            b[i][j] = a[i][j];//����������ͬ������
        }
    for (i = 0; i < n; i++)//�ҳ������е����ֵ
        for (j = 0; j < n; j++)
            a[0][0] = (a[0][0] > a[i][j]) ? a[0][0] : a[i][j];
    for (i = 0; i < n; i++)//�ҳ����ֵ���ڵ�λ�ò����
        for (j = 0; j < n; j++)
            if (b[i][j] == a[0][0])
                printf("%d %d %d\n", a[0][0], i+1, j+1);
}
