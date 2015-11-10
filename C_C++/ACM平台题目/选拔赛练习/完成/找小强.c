#include <stdio.h>

int main(void)
{
    int T, i, j, n, rows, cols;

    scanf("%d", &T);//输入测试数据的组数
    for (n = 0; n < T; n++)//循环控制
    {
        scanf("%d %d", &rows, &cols);//输入房间的行列数

        int a[rows][cols], x, y, sum;//定义并初始化变量

        for (i = 0; i < rows; i++)
            for (j = 0; j < cols; j++)
                scanf("%d", &a[i][j]);//输入二维数组

        while (scanf("%d %d", &x, &y) != EOF)//输入小丹所在的位置
        {
            if (x == -1 && y == -1)
                break;
            sum = 0;
            for (i = 0; i < rows; i++)//累加小丹3*3范围内的小强数目
                for (j = 0; j < cols; j++)
                    if((i >= x - 1 && i <= x + 1) && (j >= y - 1 && j <= y + 1))
                        sum += a[i][j];

            printf("%d\n", sum);//输出
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
