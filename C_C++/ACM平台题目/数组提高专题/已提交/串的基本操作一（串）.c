#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000], ch[1000];//�����ַ�����
    int i, j, x, z = 0, flage;//�������

    gets(str);//����ַ���

    for (i = 0; i < strlen(str); i++)//ѭ���ж��Ƿ����ظ��ַ�
    {
        flage = 1;//��ʼ����ʶ��

        for (j = 0; j < i; j++)//��һ���ַ���������ظ����ַ�
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
        flage = 1;//��ʼ����ʶ��

        for (j = 0; j < i; j++)
            if (ch[i] == ch[j])
                flage = 0;
        if (flage)
            putchar(ch[i]);
    }
    printf("\n");

    return 0;
}
