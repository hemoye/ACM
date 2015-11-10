#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[1001], str2[1001];//定义声明

    while (scanf("%s%s", str1, str2) != EOF)//控制无限输入字符串
    {
        int i, j, num1, num2, sum1, sum2, flage = 0;//定义声明
        int a[1000] = {0}, b[1000] = {0}, c[1000] = {0};//定义并初始化三个数组
        if (strcmp (str1, "0") == 0 || strcmp (str2, "0") == 0)
        {
            printf("0\n");
            continue;
        }

        for (i = num1 = num2 = 0; i < strlen(str1); i++)
        {
            if (str1[i] == '.')
            {
                flage = 1;//遇到小数点则令标识符为1并跳过余下语句
                continue;
            }
            a[num1++] = str1[i] - '0';//字符转化为数字存进数组
            if (flage)
                num2++;//累加小数点后的数字位数
        }
        //printf("%d %d\n", num1, num2);
        for (i = sum1 = sum2 = flage = 0; i < strlen(str2); i++)
        {
            if (str2[i] == '.')
            {
                flage = 1;//遇到小数点则令标识符为1并跳过余下语句
                continue;
            }
            b[sum1++] = str2[i] - '0';//字符转化为数字存进数组
            if (flage)
                sum2++;//累加小数点后的数字位数
        }
        //printf("%d %d\n", sum1, sum2);
        for (i = 0; i < num1; i++)
            for (j = 0; j < sum1; j++)
                c[i+j+1] += a[i] * b[j];//累加各个位数上的乘积

        for (i = num1 + sum1 - 1; i > 0; i--)
            while (c[i] > 9)//十进制,滿十进一
            {
                c[i] -= 10;
                c[i-1] += 1;
            }
        if (c[0])//如果最高位不是0则输出c[0]
            printf("%d", c[0]);
        for (i = 1; i < num1 + sum1; i++)
        {
            printf("%d", c[i]);//输出数组里面的数字
            if ((i == num1 + sum1 - num2 - num2 - 1) && i != num1 + sum1 - 1)//判断控制输出小数点
                printf(".");
        }
        printf("\n");//换行
    }

    return 0;
}
