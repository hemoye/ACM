#include <stdio.h>

int main(void)
{
    int n, m, i, j, x, y, z, Array[10][10];//�������
    int flag = 1;

    while (scanf("%d %d", &m, &n) != EOF)//�����ά�������������
    {
        flag = 1;//��ʼ������
        for (i = 0; i < m; i++)//�����ά����
            for (j = 0; j < n; j++)
                scanf("%d", &Array[i][j]);

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n - 1; j++)//�ҳ���i+1�е����ֵ
            {
                if (Array[i][j] > Array[i][j+1])
                {
                    z = Array[i][j];//�Ѵ�ֵ����z
                    x = j;//�Ѵ�ֵ���ڵ��и���x
                }
                else
                {
                    z = Array[i][j+1];
                    x = j + 1;
                }
            }
            for (y = 0; y < m; y++)//�ڵ�j�бȽ�
                if (z > Array[y][x])//ֻҪz��x�����������һ�����ִ���ֹѭ��
                    break;

            if (y == m)//���y�����ۼӵ�n����������㡣�������ѭ��
            {
                printf("Array[%d][%d]=%d\n", i, x, Array[i][x]);
                flag = 0;
            }
        }
        if (flag)
        printf("None\n");
    }

    return 0;
}
