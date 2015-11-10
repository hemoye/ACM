#include <stdio.h>

int main(void)
{
    void jiaohuan(int n, int x, int (* a)[]);

    int i, j, n, temp;//声明语句
    int sum[1000] = {0};

    scanf("%d", &n);//输入方阵的边长
    int a[n][n];//定义一个n*n的矩阵，一个包含n个元素的数组

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            sum[i] += a[i][j];
        sum[i] /= n;
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (sum[j] > sum[j+1])
            {
                temp = sum[j];
                sum[j] = sum[j+1];
                sum[j+1] = temp;
                jiaohuan(n, j, a);
            }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf((0 == j) ? "%d" : " %d", a[i][j]);
        printf("\n");
    }
    printf("\n");

    return 0;
}
void jiaohuan(int n, int x, int (* a)[n])//二维数组发送的格式
{
    int i, temp;

    for (i = 0; i < n; i++)
    {
        temp = a[x][i];
        a[x][i] = a[x+1][i];
        a[x+1][i] = temp;
    }

    return 0;
}
