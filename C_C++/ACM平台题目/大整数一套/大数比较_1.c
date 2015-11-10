#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[1001], str2[1001];//定义声明，定义两个最大数组长度+1的字符数组

    while (scanf("%s%s", str1, str2) != EOF)//控制无线输入字符串
    {
        int i, num1, num2;//定义声明

        for (i = num1 = 0; i < strlen(str1); i++)
            if (str1[i] == '.')//遇到小数点则终止程序
                break;
            else
                num1++;//获得字符串str1小数点前面部分的长度

        for (i = num2 = 0; i < strlen(str2); i++)
            if (str2[i] == '.')//遇到小数点则终止程序
                break;
            else
                num2++;//获得字符串str2小数点前面部分的长度
        if (num1 < num2)//如果num1小于num2，则表明第一个字符串小于第二个字符串
        {
            printf("%d\n", -1);//输出-1并跳过余下判断
            continue;
        }
        else if (num1 > num2)//如果num1大于num2，则表明第一个字符串大于第二个字符串
        {
            printf("%d\n", 1);//输出1并跳过余下判断
            continue;
        }
        else
        {
            if (strcmp (str1, str2) > 0)
            {
                printf("%d\n", 1);//输出1并跳过余下判断
                continue;
            }
            else if (strcmp (str1, str2) == 0)//输出0并跳过余下判断
            {
                printf("%d\n", 0);
                continue;
            }
            else
                printf("%d\n", -1);
        }
    }

    return 0;
}
