#include <stdio.h>

void maopao(int * , int );//函数声明

int main(void)//主函数
{
    int n, i, j, num;//声明语句

    while (scanf("%d", &n) != EOF)//输入马匹数量
    {
        if (0 == n)
            break;
        int ziyuan[n], duishou[n];//定义两个数组长度为n的数组

        for (i = 0; i < n; i++)
            scanf("%d", &ziyuan[i]);//输入子渊的马匹速度
        for (i = 0; i < n; i++)
            scanf("%d", &duishou[i]);//输入对手的马匹速度

        maopao(ziyuan, n);//调用函数
        maopao(duishou, n);//调用函数

        for (i = j = num = 0; i < n; i++)//逐渐比较子渊与对手的马匹速度
            if (ziyuan[i] > duishou[j])//如果子渊的马匹速度大于对手的马匹速度
            {
                j++;                   //则比较对手速度比前一匹大的马
                num++;                 //并且num自加
            }

        printf((num > n / 2) ? "YES\n" : "NO\n");//判断并输出子渊的输赢情况
    }

    return 0;
}

void maopao(int * pArr, int n)//定义函数冒泡法对数组进行排序
{
    int i, j, t;//声明语句

    for (i = 0; i < n - 1; i++)//冒泡法排序
        for (j = 0; j < n - i - 1; j++)
            if (pArr[j] > pArr[j+1])//如果前一项的值大于后一项的值，则交换两者的值
            {
                t = pArr[j];
                pArr[j] = pArr[j+1];
                pArr[j+1] = t;
            }

    return 0;
}
