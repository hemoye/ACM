#include <stdio.h>

void main(void)
{
    int a[50];  /*数组a存放圈中人的编号*/
    int i, j, k, n, m;

    scanf("%d %d", &n, &m);//输入游戏人数和杀死的人的编号
    for(i = 0; i < n; i++)    //对圈中人按顺序编号1 ~ n
        a[i] = i + 1;
    for(i = n, j = 0; i > 1; i--)
    {
        /*i表示圈中人个数，初始为n个，剩1个人时结束循环；j表示当前报数人的位置*/
        for (k = 1; k <= m; k++)   /*1至N报数*/
            if(++j > i - 1)
                j = 0;/*最后一个人报数后第一个人接着报，形成一个圈*/
        if (j)
            for(k = --j; k < i; k++)  /*压缩数组a，使报数为N的人出圈*/
                a[k] = a[k+1];
    }
    printf("%d\n", a[0]);//输出圈中最后一个人的编号

    return 0;
}
