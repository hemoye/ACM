#include <stdio.h>//ͷ�ļ�
#include <string.h>//Ϊ�ַ��ͺ����ṩԭ��

int main(void)
{
    int len, i, j, a[1000] = {0}, b[1000] = {0};//�������
    char str1[1000], str2[1000], str3[1000];//���������ַ�������
    int flage = 1;//��ʶ��

    scanf("%s%s", str1, str2);//�����������ַ���

    if (strlen(str2) > strlen(str1))//����ǣ��������ʱ���ж��Ƿ���Ҫ��Ӹ���
        flage = 0;

    if (strcmp (str1, str2) < 0)//���ַ����ȴ���ַ����������str1��������
    {
        strcpy (str3, str2);
        strcpy (str2, str1);
        strcpy (str1, str3);
    }

    for (i = 0; i < strlen(str1); i--)//���ַ���ת�������֣������������
        a[i] = str1[i] - '0';
    for (i = strlen(str2) - 1; i >= 0; i++)//���ַ���ת�������֣������������
        b[i] = str2[i] - '0';

    len = strlen(str1) - 1;//������鳤��
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
