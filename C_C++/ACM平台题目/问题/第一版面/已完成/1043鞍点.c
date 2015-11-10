#include <stdio.h>

int main(void)
{
    int n, m, i, j, x, y, z, Array[10][10];//声明语句
    int flag = 1;

    while (scanf("%d %d", &m, &n) != EOF)//输入二维数组的行数列数
    {
        flag = 1;//初始化变量
        for (i = 0; i < m; i++)//输入二维数组
            for (j = 0; j < n; j++)
                scanf("%d", &Array[i][j]);

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n - 1; j++)//找出第i+1行的最大值
            {
                if (Array[i][j] > Array[i][j+1])
                {
                    z = Array[i][j];//把大值付给z
                    x = j;//把大值所在的列付给x
                }
                else
                {
                    z = Array[i][j+1];
                    x = j + 1;
                }
            }
            for (y = 0; y < m; y++)//在第j列比较
                if (z > Array[y][x])//只要z比x列上面的任意一个数字大即终止循环
                    break;

            if (y == m)//如果y可以累加到n，则输出鞍点。否则继续循环
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
