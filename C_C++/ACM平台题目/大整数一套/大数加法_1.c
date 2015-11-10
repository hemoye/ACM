#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[1001], str2[1001];
    int i, j, num1, num2, x, y, z;//定义声明

    while (scanf("%s%s", str1, str2) != EOF)//输入字符串
    {
        int a1[500] = {0}, a2[50] = {0}, b1[500] = {0}, b2[50] = {0}, c1[500] = {0}, c2[500] = {0};//定义声明

        for (i = j = num1 = 0; i < strlen(str1); i++)//取出字符串中的数字
        {
            if (str1[i] == '.')//遇到小数点则终止前面部分的转化
                break;
            else
                a1[++num1] = str1[i] - '0';//取得一个字符串小数点前面部分的所有数字
        }
        for (i = num1; i < strlen(str1); i++)//取得小数点后面的所有数字
            a2[++j] = str1[i] - '0';
        for (i = j = num2 = 0; i < strlen(str2); i++)
        {
            if (str2[i] == '.')
                break;
            else
                b1[++num2] = str2[i] - '0';//取得一个字符串小数点前面部分的所有数字
        }
        for (i = num2; i < strlen(str2); i++)//取得小数点后面的所有数字
            b2[++j] = str2[i] - '0';

        x = (strlen(str1) - num1 > strlen(str2) - num2) ? (strlen(str1) - num1) : (strlen(str2) - num2);//取得小数点后的最长位数
        z = y = (num1 > num2) ? num1 : num2;//取得小数点前面的最长位数

        for (i = x; i > 2; i--)//从最后一位开始累加，加到小数点后一位
        {
            c2[i] += a2[i] + b2[i];//累加两个数列每一个位置上的和
            if (c2[i] > 9)//判断该和是否需要进位
            {
                c2[i] -= 10;//十进制进位
                c2[i-1] += 1;
            }
        }
        c2[i] += a2[i] + b2[i];//加得小数点后一位数字的和
        if (c2[2] > 9)//判断小数点后的第一位数之和是否大于9需要进位
        {
            c2[2] -= 10;//十进制进位
            a1[num1] += 1;
        }
        for (i = num1, j = num2; y > 0; y--, j--, i--)
        {
            c1[i] += a1[i] + b1[j];
            if (c1[i] > 9)
            {
                c1[i] -= 10;//十进制进位
                c1[i-1] += 1;
            }
        }
        if (c1[0])//判断最高位是否为0，如果为0则不输出
            printf("%d", c1[0]);
        for (i = 1; i <= z; i++)//输出每一个位置上的数字
            printf("%d", c1[i]);
        if (num1 != strlen(str1) || num2 != strlen(str2))//判断有没有小数点部分
        {
            printf(".");//如果有则输出小数点
            for (i = 2; i <= x; i++)//小数点后面的每一位数字
                printf("%d", c2[i]);
        }
        printf("\n");//换行
    }

    return 0;
}
