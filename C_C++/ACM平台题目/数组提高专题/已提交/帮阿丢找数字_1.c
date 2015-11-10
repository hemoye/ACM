#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j;//定义声明
    char str[1001];//定义一个字符数组，最大长度+1

    while (gets(str) != NULL)
    {
        unsigned long long sum = 0;//定义并初始化变量

        for (i = 0; i < strlen(str); i++)
            if (str[i] >= '0' && str[i] <= '9')//如果是数字则进行转化
                sum = sum * 10 + (str[i] - '0');//括号内部是把字符数字转化成数字

        printf("%d\n", sum);//输出字符串经过转化后的数字
    }

    return 0;
}
