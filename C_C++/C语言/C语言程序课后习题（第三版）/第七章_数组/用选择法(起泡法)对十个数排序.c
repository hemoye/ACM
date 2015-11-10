#include <stdio.h>
int main(void)
{
    int i, j, t, a[10];

    for (i = 0; i < 10; i++)//数组输入
        scanf("%d", &a[i]);

    for (i = 0; i < 10; i++)   //冒泡法排序
        for (j = 0; j < 9; j++)
            if (a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }

    for (i = 0; i < 10; i++)//输出数组
        printf("%d ", a[i]);
    printf("\n");
}
