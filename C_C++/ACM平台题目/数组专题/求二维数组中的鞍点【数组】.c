#include <stdio.h>

int main(void)
{
    int m, n, k, rows, z;
    int i, j, Array[24][24];//声明语句

    scanf("%d %d", &m, &n);//输入二维数组的行数列数

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &Array[i][j]);//输入二维数组

    for (i = j = 0; i < m; i++)
    {
        z = 1000000;
        for (j = 0; j < n; j++)//在第i行上查找最小值
        {
            if (z > Array[i][j])
            {
                z = Array[i][j];//把最小值赋给z
                rows = j;
            }
        }
        for (k = 0; k < m; k++)//在第j-1列上判断z是不是最小值
            if (z > Array[k][rows])//如果z是最小值则k能累加至m，否则不能
                break;
        if (k == m)//如果k能够累加至m，则输出找到的鞍点
            printf("%d ", z);
    }
    printf ("\n");

    return 0;
}
