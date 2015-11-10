#include <stdio.h>
#include <string.h>

int main(void)
{
    int judge(char str1[], char str2[]);

    int flage;
    unsigned i, j, t, m, n;//声明语字符句
    char str[100][20], ch[20];//定义一个二维字符串

    scanf("%d", &t);//控制循环的次数
    for (m = 0; m < t; m++)
    {
        flage = 1;//标识符
        scanf("%d", &n);//输入电话号码的个数
        for (i = 0; i < n; i++)
            scanf("%s", str[i]);//获得电话号码

        for (i = 0; i < n - 1; i++)//循环判断电话号码是否合法
        {
            for (j = i + 1; j < n; j++)
                if (0 == judge(str[i], str[j]))//循环调用函数
                {
                    flage = 0;//改变标识符的值
                    break;
                }
            if (0 == flage)//如果标识符为0，直接跳出整个循环
                break;
        }
        printf((0 == flage) ? "NO\n" : "YES\n");//如果标识符为0则输出NO,否则输出YES
    }

    return 0;
}
int judge(char str1[], char str2[])//定义函数判断两个字符串中长度短的字符串与长的字符串前面部分是否相同
{
    int len, i, j;//声明语句
    char str[20];//定义一个字符串数组

    len = (strlen(str1) > strlen(str2)) ? strlen(str2) : strlen(str1);//把字符串长度短的字符串长度赋给len

    if (strlen(str1) < strlen(str2))//把字符长度短的字符串放在str1
    {
        strcpy (str, str2);
        strcpy (str2, str1);
        strcpy (str1, str);
    }

    for (i = 0; i < len - 1; i++)
        if (str1[i] != str2[i])//如果有不相同的字符就终止程序并返回数字1，否则继续循环
            return 1;

    return 0;//如果能够完成循环则表明两个字符串的前len个字符完全相同，则终止程序并返回数字0
}
