#include <stdio.h>
#include <string.h>

int main(void)
{
    int judge(char ch);//��������

    char str[1001][1001], ch[1001];//����һ����ά�ַ������һ��һά�ַ�����
    int i, j, z, flage, num = 0;//�������

    while (scanf("%s", str[num++]) != EOF);//��EOF�������뵥��

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
                if (judge(str[i][z-1]) && str[i][z] == 'y' && judge(str[i][z+3]))//�ж���ĸyǰһλ�ͺ���λ�ǲ�����ĸ
                {
                    strncpy (ch, str[i]+z, 3);//������ǣ������ĸy�ĺ�����Ƹ�ch�ַ�����
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
int judge(char ch)//���庯��
//�������ܣ��ж��ַ��ǲ�����ĸ
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 0;
    else
        return 1;
}
