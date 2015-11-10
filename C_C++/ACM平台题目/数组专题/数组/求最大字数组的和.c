#include <stdio.h>

int main(void)
{
    int i, j, k, z = 0, max = 0;

    int a[8], b[28];//定义两个数组


    for (i = 0; i < 8; i++)
        scanf("%d", &a[i]);//输入数组

    for (i = 0; i < 8; i++)//求所有字段的和，并存入数组b
        for (k = i + 1; k < 8; k++)
        {
            b[z] = a[i];
            for (j = i + 1; j <= k; j++)
                b[z] += a[j];
            if (max < b[z])
                max = b[z];
            z++;
        }

    printf("%d\n", max);//输出b数组中的最后一位数字

    return 0;
}
