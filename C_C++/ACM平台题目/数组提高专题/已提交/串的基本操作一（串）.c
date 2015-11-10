#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000], ch[1000];//定义字符数组
    int i, j, x, z = 0, flage;//声明语句

    gets(str);//获得字符串

    for (i = 0; i < strlen(str); i++)//循环判断是否是重复字符
    {
        flage = 1;//初始化标识符

        for (j = 0; j < i; j++)//用一个字符数组接收重复的字符
            if (str[i] != str[j])
            {

                flage = 0;
                break;
            }
            else
                ch[z++] = str[i];
        if (flage)
            putchar(str[i]);
    }
    printf("\n%s\n", ch);
    for (i = 0; i < z; i++)
    {
        flage = 1;//初始化标识符

        for (j = 0; j < i; j++)
            if (ch[i] == ch[j])
                flage = 0;
        if (flage)
            putchar(ch[i]);
    }
    printf("\n");

    return 0;
}
