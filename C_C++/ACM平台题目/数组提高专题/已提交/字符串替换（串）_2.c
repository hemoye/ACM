#include <stdio.h>
#include <string.h>

int main(void)
{
    char c[6], ch[1001], str[1001][1001];
    int i, j, num;

    gets(ch);

    for (i = j = num = 0; i < strlen(ch); i++)//截取字符串中的单词
        if (ch[i] == ' ')//以空格为分割
        {
            num++;
            j = 0;
        }
        else
            str[num][j++] = ch[i];//截取字符串中的单词

    for (i = 0; i <= num; i++)
    {
        for (j = 1; j < strlen(str[i]); j++)
            if (!((str[i][j-1]>='a'&&str[i][j-1]<='z')&&(str[i][j-1]>='A'&&str[i][j-1]<='Z'))&&str[i][j]=='y'&&str[i][j+1]=='o'&&str[i][j+2]=='u'&&(!(str[i][j+3]>='a'&&str[i][j+3]<='z')&&(str[i][j+3]>='A'&&str[i][j+3]<='Z')))
            {
                strncpy (ch, str[i]+j, 3);
                ch[3] = '\0';
            }
        strncpy (c, str[i], 3);

        if (strcmp (str[i], "you") == 0)//判断字符串是否为you，是则替换
        {
            strncpy (str[i], "we", 2);
            str[i][2] = '\0';
        }

        if (strcmp (ch, "you") == 0 && (!((str[i][3]>='a'||str[i][3]<='z')&&(str[i][3]>='A'||str[i][3]<='Z'))))
        {
            strncpy (str[i], "we", 2);
            for (j = 3; j < strlen(str[i]); j++)
                str[i][j-1] = str[i][j];
            str[i][j-1] = '\0';
        }
        if (strcmp (c, "you") == 0 && (!((str[i][3]>='a'||str[i][3]<='z')&&(str[i][3]>='A'||str[i][3]<='Z'))))
        {
            strncpy (str[i], "we", 2);
            for (j = 3; j < strlen(str[i]); j++)
                str[i][j-1] = str[i][j];
            str[i][j-1] = '\0';
        }
    }
    for (i = 0; i <= num; i++)
        printf((0 == i) ? "%s" : " %s", str[i]);
    printf("\n");

    return 0;
}
