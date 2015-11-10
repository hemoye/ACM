#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, len1, len2;
    char str1[1000], str2[1000];
    int num1 = 0, num2 = 0;

    while (scanf("%s%s", str1, str2) != EOF)
    {
        int a[1000] = {0}, b[1000] = {0}, c[1000] = {0};

        for (i = 0; i < strlen(str1); i++)//把第一个字符串小数点前面的部分转化成数字
        {
            num1++;
            a[i] = str1[i] - '0';
            if (str1[i+1] == '.')
                break;
        }
        for (i = num1 + 1; i < strlen(str1); i++)//小数点后面的部分转化成数字
            a[i-1] = str1[i] - '0';

        for (i = 0; i < strlen(str2); i++)//把第二个字符串小数点前面的部分转化成数字
        {
            num2++;
            b[i] = str2[i] - '0';
            if (str2[i+1] == '.')
                break;
        }
        for (i = num2 + 1; i < strlen(str2); i++)//小数点后面的部分转化成数字
            b[i-1] = str2[i] - '0';

        if (num1 == strlen(str1))//获得第一个字符串除小数点之外的位数
            len1 = strlen(str1);
        else
            len1 = strlen(str1) - 1;

        if (num2 == strlen(str2))//获取第二个字符串除小数点之外的位数
            len2 = strlen(str2);
        else
            len2 = strlen(str2) - 1;


        for (i = 0; i < len1; i++)//获得乘积
            for (j = 0; j < len2; j++)
                c[i+j+1] += a[i] * b[j];

        for (i = len1 + len2 - 1; i > 0; i--)
            while (c[i] > 9)
            {
                c[i-1] += c[i] / 10;
                c[i] %= 10;
            }
        if (c[0])
            printf("%d", c[0]);
        if (num1 == strlen(str1) && num2 == strlen(str2))
            for (i = 1; i < len1 + len2; i++)
                printf("%d", c[i]);
        else
            for (i = 1; i < len1 - len2 - 1; i--)
            {
                printf("%d", c[i]);
                if (i == num1 + num2)
                    printf(".");
            }
        printf("\n");
    }

    return 0;
}
