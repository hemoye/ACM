#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, len1, len2;
    char str1[1000], str2[1000];
    int num1 = 0, num2 = 0;

    while (scanf("%s%s", str1, str2) != EOF)
    {
        int a[1000] = {0}, b[1000] = {0}, c[1000] = {0};

        for (i = 0; i < strlen(str1); i++)//�ѵ�һ���ַ���С����ǰ��Ĳ���ת��������
        {
            num1++;
            a[i] = str1[i] - '0';
            if (str1[i+1] == '.')
                break;
        }
        for (i = num1 + 1; i < strlen(str1); i++)//С�������Ĳ���ת��������
            a[i-1] = str1[i] - '0';

        for (i = 0; i < strlen(str2); i++)//�ѵڶ����ַ���С����ǰ��Ĳ���ת��������
        {
            num2++;
            b[i] = str2[i] - '0';
            if (str2[i+1] == '.')
                break;
        }
        for (i = num2 + 1; i < strlen(str2); i++)//С�������Ĳ���ת��������
            b[i-1] = str2[i] - '0';

        if (num1 == strlen(str1))//��õ�һ���ַ�����С����֮���λ��
            len1 = strlen(str1);
        else
            len1 = strlen(str1) - 1;

        if (num2 == strlen(str2))//��ȡ�ڶ����ַ�����С����֮���λ��
            len2 = strlen(str2);
        else
            len2 = strlen(str2) - 1;


        for (i = 0; i < len1; i++)//��ó˻�
            for (j = 0; j < len2; j++)
                c[i+j+1] += a[i] * b[j];

        for (i = len1 + len2 - 1; i > 0; i--)
            while (c[i] > 9)
            {
                c[i-1] += c[i] / 10;
                c[i] %= 10;
            }
        if (c[0])
            printf("%d", c[0]);
        if (num1 == strlen(str1) && num2 == strlen(str2))
            for (i = 1; i < len1 + len2; i++)
                printf("%d", c[i]);
        else
            for (i = 1; i < len1 - len2 - 1; i--)
            {
                printf("%d", c[i]);
                if (i == num1 + num2)
                    printf(".");
            }
        printf("\n");
    }

    return 0;
}
