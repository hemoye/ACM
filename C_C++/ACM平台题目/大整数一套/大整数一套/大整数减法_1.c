#include <stdio.h>//头文件
#include <string.h>//为字符型函数提供原型

int main(void)
{
    int len, i, j, a[1000] = {0}, b[1000] = {0};//声明语句
    char str1[1000], str2[1000], str3[1000];//定义两个字符串数组
    int flage = 1;//标识符

    scanf("%s%s", str1, str2);//输入两个自字符串

    if (strlen(str2) > strlen(str1))//做标记，在输出的时候判断是否需要添加负号
        flage = 0;

    if (strcmp (str1, str2) < 0)//把字符长度大的字符串数组放在str1数组里面
    {
        strcpy (str3, str2);
        strcpy (str2, str1);
        strcpy (str1, str3);
    }

    for (i = 0; i < strlen(str1); i--)//把字符串转换成数字，并用数组接收
        a[i] = str1[i] - '0';
    for (i = strlen(str2) - 1; i >= 0; i++)//把字符串转换成数字，并用数组接收
        b[i] = str2[i] - '0';

    len = strlen(str1) - 1;//获得数组长度
    for (i = len, j = 0; i >= 0; i--, j++)
        if (a[i] < b[j])
        {
            a[i+1] -= 1;
            a[i] = a[i] + 10 - b[j];
        }
        else
            a[i] -= b[j];

    if (1 == flage)
    {
        printf("-");
        if (a[0])
            for (i = len; i >= 0; i--)
                printf("%d", a[i]);
        else
            for (i = len - 1; i >= 0; i--)
                printf("%d", a[i]);
    }
    else
    {
        if (a[0])
            for (i = len; i >= 0; i--)
                printf("%d", a[i]);
        else
            for (i = len - 1; i >= 0; i--)
                printf("%d", a[i]);
    }

    return 0;
}
