#include <stdio.h>
#include <string.h>//Ϊ�ַ������ṩԭ��

int main(void)
{
    int judge(char str1[], char str2[]);//��������

    int i, j, flage;//�������
    int a[1000] = {0}, b[1000] = {0};//���岢��ʼ����������
    char str1[1000], str2[1000];//���������ַ���

    scanf("%s%s", str1, str2);

    if (strcmp (str1, str2) == 0)
    {
        printf("0\n");
        return 0;
    }

    flage = judge(str1, str2);//���ú���������flage���պ����ķ���ֵ

    if (flage == 1)//����������ڱ���������ִ��
    {
        for (i = strlen(str1) - 1, j = strlen(str1) - 1; j >= 0; i--, j--)
            a[i] = str1[i] - '0';//�������ַ�ת�������ֲ�����������
        for (i = strlen(str1) - 1, j = strlen(str2) - 1; j >= 0; i--, j--)
            b[i] = str2[j] - '0';
        for (i = strlen(str1); i >= 0; i--)
        {//ѭ�����
            if (b[i] > a[i])//�����������ĳһλ���ϴ��ڼ������������һλ�Լ�1
            {
                a[i-1] -= 1;
                a[i] = a[i] + 10 - b[i];
            }
            else
                a[i] -= b[i];
        }
        if (a[0])//�����һλ���ֲ���������
            for (i = 0; i < strlen(str1); i++)
                printf("%d", a[i]);
        else//�������
            for (i = 1; i < strlen(str1); i++)
                printf("%d", a[i]);
    }
    else//������������ڼ�������ִ��else�ڲ����
    {
        for (i = strlen(str2) - 1, j = strlen(str2) - 1; j >= 0; i--, j--)
            a[i] = str2[i] - '0';
        for (i = strlen(str2) - 1, j = strlen(str1) - 1; j >= 0; i--, j--)
            b[i] = str1[j] - '0';
        for (i = strlen(str2); i >= 0; i--)
        {
            if (b[i] > a[i])
            {
                a[i-1] -= 1;
                a[i] = a[i] + 10 - b[i];
            }
            else
                a[i] -= b[i];
        }
        printf("-");
        if (a[0])
            for (i = 0; i < strlen(str2); i++)
                printf("%d", a[i]);
        else
            for (i = 1; i < strlen(str2); i++)
                printf("%d", a[i]);
    }

    return 0;
}
int judge(char str1[], char str2[])//�ж��ַ������ִ�С���������
{
    int i;

    if (strlen(str1) < strlen(str2))//����ڶ����ַ������򷵻�0
        return 0;
    else if (strlen(str1) > strlen(str2))//�����һ���ַ������򷵻�1
        return 1;
    else//�������ַ�������һ����ʱ������ѭ���Ƚ�ÿһ���ַ��Ĵ�С
        if (strcmp (str1, str2) > 0)
            return 1;
        else if (str1[i] < str2[i])
            return 0;
}
