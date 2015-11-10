#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[1000], str2[1000];//定义两个字符数组
    int a[1000] = {0};//定义一个数组
    int i, j, len;//声明语句

    scanf("%s%s", str1, str2);//输入两个字符串

    for (i = 0; i < strlen(str1); i++)//累加各个位数上乘积的和
        for (j = 0; j < strlen(str2); j++)
            a[i+j+1] += (str1[i] - '0') * (str2[j] - '0');//a[0]作为最高位

    for (len = strlen(str1) + strlen(str2) - 1; len > 0; len--)
        while (a[len] > 9)
        {
            a[len-1] += a[len] / 10;//十进制大于10就进一
            a[len] %= 10;
        }

    if (a[0])//如果最高位不是0就输出
        printf("%d", a[0]);
    for (i = 1; i < strlen(str1) + strlen(str2); i++)//输出乘积的值
        printf("%d", a[i]);
    printf("\n");

    return 0;
}
