#include <stdio.h>

int main(void)
{
    void function(int * str, int * n);//函数声明

    int i, j, n, t, T, str[1000];//声明语句

    scanf("%d", &T);//输入测试数据的组数
    for (t = 0; t < T; t++)
    {
        scanf("%d", &n);//输入每一组测试数据中数字的个数

        for (i = 0; i < n; i++)
            scanf("%d", &str[i]);//输入一维数组

        printf("Case #%d:\n", t+1);

        function(str, n);//调用函数
    }

    return 0;
}
void function(int * str, int * n)
{
    int num, i, j, t, x, flage;//声明语句
    int str1[1000];

    if (n < 3)//判断  如果数组长度小于3则直接输出0
        printf("0\n");
    else
    {
        for (i = x = 0; i < n; i++)//去掉数组中相同的元素
        {
            flage = 1;
            for (j = 0; j < i; j++)
                if (str[i] == str[j])
                    flage = 0;
            if (flage)
                str1[x++] = str[i];
        }

        for (i = num = 0; i < x; i++)
            for (j = i+1; j < x; j++)//三重循环判定
                for (t = j+1; t < x; t++)
                    if ((str1[i] != str1[j]) && (str1[i] != str1[t]) && (str1[t]) != str1[j])
                        num++;
        printf("%d\n", num);//输出符合题目要求的组合个数
    }
}
