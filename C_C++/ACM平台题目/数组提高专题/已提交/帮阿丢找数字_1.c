#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j;//��������
    char str[1001];//����һ���ַ����飬��󳤶�+1

    while (gets(str) != NULL)
    {
        unsigned long long sum = 0;//���岢��ʼ������

        for (i = 0; i < strlen(str); i++)
            if (str[i] >= '0' && str[i] <= '9')//��������������ת��
                sum = sum * 10 + (str[i] - '0');//�����ڲ��ǰ��ַ�����ת��������

        printf("%d\n", sum);//����ַ�������ת���������
    }

    return 0;
}
