#include <stdio.h>

int main(void)
{
    int i, j, temp, jishu = 0, oushu = 0;//定义变量
    int a[100] = {0}, b[100] = {0}, c[100] = {0};//声明三个数组

    for (i = 0; i < 8; i++)
        scanf("%d", &a[i]);//输入数组
    for (i = 0; i < 8; i++)
        if (0 == a[i] % 2)//如果a[i]是偶数则执行if内部语句
        {
            b[oushu] = a[i];//把偶数存入数组b
            oushu++;//计算偶数个数
        }
        else
        {
            c[jishu] = a[i];//把奇数存入数组c
            jishu++;//计算奇数个数
        }
    for (i = 0; i < jishu; i++)
        for (j = 0; j < jishu - 1 - i; j++)
            if (c[j] < c[j+1])//对保存了所有奇数的数组降序排序
            {
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
    for (i = 0; i < jishu; i++)
        for (j = 0; j < jishu - 1 - i; j++)
            if (b[j] > b[j+1])//对保存了所有偶数的数组升序排序
            {
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
    for (i = 0; i < jishu; i++)//输出排序后的奇数数组
        printf((0 == i) ? "%d" : " %d", c[i]);
    for (i = 0; i < oushu; i++)//输出排序后的偶数数组
        printf(" %d", b[i]);
    printf("\n");

    return 0;
}
