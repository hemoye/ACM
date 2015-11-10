#include <stdio.h>

int main(void)
{
    int Judge(unsigned char str[]);//函数声明
    int judge(int a);

    unsigned char str[30];//定义一个数组长度为30的字符串数组

    while (gets (str) != NULL)//无限输入字符串
        printf(Judge(str) ? "Y\n" : "N\n");//调用函数Judge并判断

    return 0;
}

int Judge(unsigned char str[])//构造函数
{
    int i, j, k;//变量声明
    int sum[4] = {0};//定义一个4行4列的二维数
    for (i = j = k = 0; i < strlen(str); i++)//截取str字符串数组里面的字符
    {
        if (str[i] == '.')//遇到符号.则换行接收字符
        {
            printf("%d ", sum[j]);
            j++;
            k = 0;
        }
        else
            sum[j] = sum[j] * 10 + (int)(str[i]);//把字符存入二维数组里面
    }
    for (i = 0; i < 4; i++)
    {
        if (judge(sum[i]) == 0)//调用函数判断每一个字符串是否符合IP地址的规定
            break;
    }
    if (i == 4)//如果i能够累加至4，则说明IP地址合法并返回数字1
        return 1;
    else
        return 0;
}
int judge(int a)//定义函数判断字符串
{

    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
        return 0;
    else
        return 1;
}
