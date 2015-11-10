#include <stdio.h>
#include <string.h>

int main(void)
{
    int judge(char ch);//函数声明

    char str[1001][1001], ch[1001];//定义一个二维字符数组和一个一维字符数组

    while(gets(ch) != NULL)
    {
        int i, j, z, flage, num = 0;//声明语句
        for (i = j = num = 0; i < strlen(ch); i++)//截取字符串中的单词
            if (ch[i] == ' ')//以空格为分割
            {
                num++;
                j = 0;
            }
            else
                str[num][j++] = ch[i];//截取字符串中的单词

        //ch[0] = '\0';
        for (i = z = 0; i <= num; i++)
        {
            if (strlen(str[i]) < 3)
            {
                printf((0 == i) ? "%s" : " %s", str[i]);
                continue;
            }

            if (strlen(str[i]) == 3 && (strcmp (str[i], "you") == 0))
                strcpy (str[i], "we");
            if (str[i][0] == 'y' && strlen(str[i]) > 3)
            {
                if (judge(str[i][3]) && str[i][1] == 'o' && str[i][2] == 'u')
                {
                    strncpy (str[i], "we", 2);
                    for (j = 3; j < strlen(str[i]); j++)
                        str[i][j-1] = str[i][j];
                    str[i][j-1] = '\0';
                    for (z = 1; z < strlen(str[i]); z++)
                        if (judge(str[i][z-1]) && str[i][z] == 'y' && str[i][z+1] == 'o' && str[i][z+2] == 'u' && judge(str[i][z+3]))//判断字母y前一位和后三位是不是字母
                        {
                            strncpy (ch, str[i]+z, 3);//如果不是，则把字母y的后三项复制给ch字符数组
                            ch[3] = '\0';
                            break;
                        }
                }
                else
                {
                    for (z = 1; z < strlen(str[i]); z++)
                        if (judge(str[i][z-1]) && str[i][z] == 'y' && str[i][z+1] == 'o' && str[i][z+2] == 'u' && judge(str[i][z+3]))//判断字母y前一位和后三位是不是字母
                        {
                            strncpy (ch, str[i]+z, 3);//如果不是，则把字母y的后三项复制给ch字符数组
                            ch[3] = '\0';
                            break;
                        }
                }
                if (strcmp (ch, "you") == 0)
                {
                    strncpy (str[i]+z, "we", 2);

                    for (j = z+3; j < strlen(str[i]); j++)
                        str[i][j-1] = str[i][j];
                    str[i][j-1] = '\0';
                    printf((0 == i) ? "%s" : " %s", str[i]);
                    continue;
                }
            }
            ch[0] = '\0';
            if (str[i][0] != 'y')
            {
                for (z = 1; z < strlen(str[i]) - 2; z++)
                    if (judge(str[i][z-1]) && str[i][z] == 'y' && judge(str[i][z+3]))//判断字母y前一位和后三位是不是字母
                    {
                        strncpy (ch, str[i]+z, 3);//如果不是，则把字母y的后三项复制给ch字符数组
                        ch[3] = '\0';
                        break;
                    }
                if (strcmp (ch, "you") == 0)
                {
                    strncpy (str[i]+z, "we", 2);
                    for (j = z+3; j < strlen(str[i]); j++)
                        str[i][j-1] = str[i][j];
                    str[i][j-1] = '\0';
                }
            }
            ch[0] = '\0';

            printf((0 == i) ? "%s" : " %s", str[i]);
        }
        printf("\n");
        for(i = 0; i <= num; i++)
            memset(str[i], '\0', 1000);
    }
    return 0;
}
int judge(char ch)//定义函数
//函数功能：判断字符是不是字母
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 0;
    else
        return 1;
}
