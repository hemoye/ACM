#include <stdio.h>

int main(void)
{
    int m, n, k, rows, z;
    int i, j, Array[24][24];//�������

    scanf("%d %d", &m, &n);//�����ά�������������

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &Array[i][j]);//�����ά����

    for (i = j = 0; i < m; i++)
    {
        z = 1000000;
        for (j = 0; j < n; j++)//�ڵ�i���ϲ�����Сֵ
        {
            if (z > Array[i][j])
            {
                z = Array[i][j];//����Сֵ����z
                rows = j;
            }
        }
        for (k = 0; k < m; k++)//�ڵ�j-1�����ж�z�ǲ�����Сֵ
            if (z > Array[k][rows])//���z����Сֵ��k���ۼ���m��������
                break;
        if (k == m)//���k�ܹ��ۼ���m��������ҵ��İ���
            printf("%d ", z);
    }
    printf ("\n");

    return 0;
}
