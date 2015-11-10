#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000];
    int i, len;

    while (gets(str) != NULL)
    {
        float a = 0;

        len = strlen(str) - 1;

        for (i = 0; i <= len; i++)
        {
            if (str[i] == '.')//当遇到小数点时直接终止循环
                break;
            else
                a = a * 10 + (str[i] - '0');//获得字符串数字转换成的数字
        }
        //printf("%d %d\n", i, len);
        if (i == len - 1)
            a = a * 100 + (str[i+1] - '0') * 10;
        else if (i == len - 2)
            a = a * 1000 + (str[i+1] - '0') * 100 + (str[i+2] - '0') * 10;
        else if (i < len - 2)
            a = a * 1000 + (str[i+1] - '0') * 100 + (str[i+2] - '0') * 10 + (str[i+3] - '0');
        else
            a *= 1000;

        printf("%.2f\n", a / 1000);
    }

    return 0;
}
