#include <stdio.h>
#include <string.h>

int main(void)
{
    int judge(char ch);//函数声明

    char str[1001][1001], ch[1001];//定义一个二维字符数组和一个一维字符数组
    int i, j, z, flage, num = 0;//声明语句

    while (scanf("%s", str[num++]) != EOF);//用EOF控制输入单词

    for (i = z = 0; i < num - 1; i++)
    {
        if (strlen(str[i]) < 3)
        {
            printf((0 == i) ? "%s" : " %s", str[i]);
            continue;
        }

        if (str[i][0] == 'y' && strlen(str[i]) == 3 && str[i][1] == 'o' && str[i][2] == 'u')
            strcpy (str[i], "we");

        else if (str[i][0] == 'y' && strlen(str[i]) > 3 && str[i][1] == 'o' && str[i][2] == 'u' && judge(str[i][3]))
        {
            strncpy (ch, str[i], 3);

            if (strcmp (ch, "you") == 0)
            {
                strncpy (str[i], "we", 2);

                for (j = 3; j < strlen(str[i]); j++)
                    str[i][j-1] = str[i][j];
                str[i][j-1] = '\0';
                printf((0 == i) ? "%s" : " %s", str[i]);
                continue;
            }
        }

        if (str[i][0] != 'y' && strlen(str[i]) > 3)
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
                for (j = 3+z; j < strlen(str[i]); j++)
                    str[i][j-1] = str[i][j];
                str[i][j-1] = '\0';
            }
        }

        printf((0 == i) ? "%s" : " %s", str[i]);
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
