#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1001][1001], ch[1001];//�����ַ�����
    int i, j, num, flage;//�������

    gets(ch);//����ַ���

    for (i = j = num = 0; i < strlen(ch); i++)//��ȡ����
    {
        if (ch[i] == ' ')//�����ո�������һ���ַ�������
        {
            num++;
            j = 0;
        }
        else if (ch[i] == '#')//����#������ȡ����
            break;
        else
            str[num][j++] = ch[i];
    }

    for (i = 0; i < num; i++)//ð�ݷ��ַ�������
        for (j = 0; j < num - i - 1; j++)
            if (strcmp (str[j], str[j+1]) > 0)//�����ַ���
            {
                strcpy (ch, str[j]);
                strcpy (str[j], str[j+1]);
                strcpy (str[j+1], ch);
            }

    for (i = 0; i < num; i++)//����ַ���
    {
        flage = 1;
        for (j = 0; j < i; j++)
            if (strcmp (str[i], str[j]) == 0)//������ͬ���ַ��������������
                flage = 0;
        if (flage)//��֮ǰ�Ĳ���ͬ�����
            puts(str[i]);
    }

    return 0;
}
