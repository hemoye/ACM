#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1001][1001], ch[1001];//定义字符数组
    int i, j, num, flage;//定义变量

    gets(ch);//获得字符串

    for (i = j = num = 0; i < strlen(ch); i++)//截取单词
    {
        if (ch[i] == ' ')//遇到空格则用另一个字符串接收
        {
            num++;
            j = 0;
        }
        else if (ch[i] == '#')//遇到#结束截取操作
            break;
        else
            str[num][j++] = ch[i];
    }

    for (i = 0; i < num; i++)//冒泡法字符串排序
        for (j = 0; j < num - i - 1; j++)
            if (strcmp (str[j], str[j+1]) > 0)//交换字符串
            {
                strcpy (ch, str[j]);
                strcpy (str[j], str[j+1]);
                strcpy (str[j+1], ch);
            }

    for (i = 0; i < num; i++)//输出字符串
    {
        flage = 1;
        for (j = 0; j < i; j++)
            if (strcmp (str[i], str[j]) == 0)//遇到相同的字符串就跳过不输出
                flage = 0;
        if (flage)//与之前的不相同则输出
            puts(str[i]);
    }

    return 0;
}
