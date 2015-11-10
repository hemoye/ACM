#include <stdio.h>

int main(void)
{
    int i, j, k, m;//定义变量

    while (scanf("%d", &m) != EOF)//输入数组的长度
    {
        if (0 == m)
            break;
        int a[m], b[m * (m - 1) / 2];//定义长度为m的数组a，长度为m * (m - 1) / 2的数组b
        int z = 0;//初始化变量

        for (i = 0; i < m; i++)//输入数组a
            scanf("%d", &a[i]);
        for (i = 0; i < m - 1; i++)//计算并存储各子段的积
            for (k = i + 1; k < m; k++)//找到距离a[i]右边的最靠近的一个数值
            {
                b[z] = a[i];//把任意子段的第一个值用b数组接收
                for (j = i + 1; j <= k; j++)
                    b[z] *= a[j];//计算子段的积
                z++;//循环完成之后存储下一个子段值
            }

        for (i = 0; i < m - 1; i++)//冒泡法对b数组进行升序排序
            for (j= 0; j < m - i; j++)
                if (b[j] > b[j+1])//如果前一项大于后一项，则交换两者的值
                {
                    k = b[j];
                    b[j] = b[j+1];
                    b[j+1] = k;
                }

        printf("%d\n", b[--z]);//输出b数组的最后的一个值
    }

    return 0;
}
