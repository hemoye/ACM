#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[1001], str2[1001];
    int i, j, num1, num2, x, y, z;//��������

    while (scanf("%s%s", str1, str2) != EOF)//�����ַ���
    {
        int a1[500] = {0}, a2[50] = {0}, b1[500] = {0}, b2[50] = {0}, c1[500] = {0}, c2[500] = {0};//��������

        for (i = j = num1 = 0; i < strlen(str1); i++)//ȡ���ַ����е�����
        {
            if (str1[i] == '.')//����С��������ֹǰ�沿�ֵ�ת��
                break;
            else
                a1[++num1] = str1[i] - '0';//ȡ��һ���ַ���С����ǰ�沿�ֵ���������
        }
        for (i = num1; i < strlen(str1); i++)//ȡ��С����������������
            a2[++j] = str1[i] - '0';
        for (i = j = num2 = 0; i < strlen(str2); i++)
        {
            if (str2[i] == '.')
                break;
            else
                b1[++num2] = str2[i] - '0';//ȡ��һ���ַ���С����ǰ�沿�ֵ���������
        }
        for (i = num2; i < strlen(str2); i++)//ȡ��С����������������
            b2[++j] = str2[i] - '0';

        x = (strlen(str1) - num1 > strlen(str2) - num2) ? (strlen(str1) - num1) : (strlen(str2) - num2);//ȡ��С�������λ��
        z = y = (num1 > num2) ? num1 : num2;//ȡ��С����ǰ����λ��

        for (i = x; i > 2; i--)//�����һλ��ʼ�ۼӣ��ӵ�С�����һλ
        {
            c2[i] += a2[i] + b2[i];//�ۼ���������ÿһ��λ���ϵĺ�
            if (c2[i] > 9)//�жϸú��Ƿ���Ҫ��λ
            {
                c2[i] -= 10;//ʮ���ƽ�λ
                c2[i-1] += 1;
            }
        }
        c2[i] += a2[i] + b2[i];//�ӵ�С�����һλ���ֵĺ�
        if (c2[2] > 9)//�ж�С�����ĵ�һλ��֮���Ƿ����9��Ҫ��λ
        {
            c2[2] -= 10;//ʮ���ƽ�λ
            a1[num1] += 1;
        }
        for (i = num1, j = num2; y > 0; y--, j--, i--)
        {
            c1[i] += a1[i] + b1[j];
            if (c1[i] > 9)
            {
                c1[i] -= 10;//ʮ���ƽ�λ
                c1[i-1] += 1;
            }
        }
        if (c1[0])//�ж����λ�Ƿ�Ϊ0�����Ϊ0�����
            printf("%d", c1[0]);
        for (i = 1; i <= z; i++)//���ÿһ��λ���ϵ�����
            printf("%d", c1[i]);
        if (num1 != strlen(str1) || num2 != strlen(str2))//�ж���û��С���㲿��
        {
            printf(".");//����������С����
            for (i = 2; i <= x; i++)//С��������ÿһλ����
                printf("%d", c2[i]);
        }
        printf("\n");//����
    }

    return 0;
}
