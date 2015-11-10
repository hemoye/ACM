#include <stdio.h>
int main(void)
{
    unsigned n;//声明语句
    int i, j, a[6][6], b[6][6];//声明语句

    scanf("%u", &n);//从键盘输入一个正整数

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            b[i][j] = a[i][j];//输入两个相同的数组
        }
    for (i = 0; i < n; i++)//找出数组中的最大值
        for (j = 0; j < n; j++)
            a[0][0] = (a[0][0] > a[i][j]) ? a[0][0] : a[i][j];
    for (i = 0; i < n; i++)//找出最大值所在的位置并输出
        for (j = 0; j < n; j++)
            if (b[i][j] == a[0][0])
                printf("%d %d %d\n", a[0][0], i+1, j+1);
}
