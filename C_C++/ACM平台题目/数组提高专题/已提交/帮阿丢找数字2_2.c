#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000];//定义一个字符数组
    int z = 0;//用于控制输出限制

    while (gets(str) != NULL)//字符串的无限输入
    {
        int i, j, a[1000] = {0};//定义并初始化变量

        for (i = j = 0; i < strlen(str); i++)//提取并转化字符串内部的数字
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                a[j] = a[j] * 10 + (str[i] - '0');//把字符串数字转化保存在数组里面
                if (!(str[i+1] >= '0' && str[i+1] <= '9'))//在累加完成子串数字字符串中的最后一个值之后，数组往后推一位
                    j++;
            }
        }
        printf("Case #%d:\n", ++z);//控制格式
        for (i = 0; i < j; i++)
            printf((0 == i) ? "%d" : " %d", a[i]);//输出数组中的数字
        printf("\n");
    }

    return 0;
}
