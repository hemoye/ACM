#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[1001], str2[1001];//������������������������鳤��+1���ַ�����

    while (scanf("%s%s", str1, str2) != EOF)//�������������ַ���
    {
        int i, num1, num2;//��������

        for (i = num1 = 0; i < strlen(str1); i++)
            if (str1[i] == '.')//����С��������ֹ����
                break;
            else
                num1++;//����ַ���str1С����ǰ�沿�ֵĳ���

        for (i = num2 = 0; i < strlen(str2); i++)
            if (str2[i] == '.')//����С��������ֹ����
                break;
            else
                num2++;//����ַ���str2С����ǰ�沿�ֵĳ���
        if (num1 < num2)//���num1С��num2���������һ���ַ���С�ڵڶ����ַ���
        {
            printf("%d\n", -1);//���-1�����������ж�
            continue;
        }
        else if (num1 > num2)//���num1����num2���������һ���ַ������ڵڶ����ַ���
        {
            printf("%d\n", 1);//���1�����������ж�
            continue;
        }
        else
        {
            if (strcmp (str1, str2) > 0)
            {
                printf("%d\n", 1);//���1�����������ж�
                continue;
            }
            else if (strcmp (str1, str2) == 0)//���0�����������ж�
            {
                printf("%d\n", 0);
                continue;
            }
            else
                printf("%d\n", -1);
        }
    }

    return 0;
}
