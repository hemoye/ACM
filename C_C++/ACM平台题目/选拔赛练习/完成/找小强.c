#include <stdio.h>

int main(void)
{
    int T, i, j, n, rows, cols;

    scanf("%d", &T);//����������ݵ�����
    for (n = 0; n < T; n++)//ѭ������
    {
        scanf("%d %d", &rows, &cols);//���뷿���������

        int a[rows][cols], x, y, sum;//���岢��ʼ������

        for (i = 0; i < rows; i++)
            for (j = 0; j < cols; j++)
                scanf("%d", &a[i][j]);//�����ά����

        while (scanf("%d %d", &x, &y) != EOF)//����С�����ڵ�λ��
        {
            if (x == -1 && y == -1)
                break;
            sum = 0;
            for (i = 0; i < rows; i++)//�ۼ�С��3*3��Χ�ڵ�Сǿ��Ŀ
                for (j = 0; j < cols; j++)
                    if((i >= x - 1 && i <= x + 1) && (j >= y - 1 && j <= y + 1))
                        sum += a[i][j];

            printf("%d\n", sum);//���
        }
    }

    return 0;
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    int sum=0;
    int n, m, row, col, t;
    int a[100][100], i, j;
    scanf("%d\n", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        scanf("%d", &a[i][j]);
        while(scanf("%d %d", &row, &col)!=EOF)
        {
            if(row==-1&&col&&-1)
            break;
            for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if((i>=row-1&&i<=row+1)&&(j>=col-1&&j<=col+1))
                    sum = sum + a[i][j];
            }
            printf("%d\n", sum);
            sum=0;
        }
    }
    return 0;
}
*/
