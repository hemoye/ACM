#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[1001], str2[1001];//��������

    while (scanf("%s%s", str1, str2) != EOF)//�������������ַ���
    {
        int i, j, num1, num2, sum1, sum2, flage = 0;//��������
        int a[1000] = {0}, b[1000] = {0}, c[1000] = {0};//���岢��ʼ����������
        if (strcmp (str1, "0") == 0 || strcmp (str2, "0") == 0)
        {
            printf("0\n");
            continue;
        }

        for (i = num1 = num2 = 0; i < strlen(str1); i++)
        {
            if (str1[i] == '.')
            {
                flage = 1;//����С���������ʶ��Ϊ1�������������
                continue;
            }
            a[num1++] = str1[i] - '0';//�ַ�ת��Ϊ���ִ������
            if (flage)
                num2++;//�ۼ�С����������λ��
        }
        //printf("%d %d\n", num1, num2);
        for (i = sum1 = sum2 = flage = 0; i < strlen(str2); i++)
        {
            if (str2[i] == '.')
            {
                flage = 1;//����С���������ʶ��Ϊ1�������������
                continue;
            }
            b[sum1++] = str2[i] - '0';//�ַ�ת��Ϊ���ִ������
            if (flage)
                sum2++;//�ۼ�С����������λ��
        }
        //printf("%d %d\n", sum1, sum2);
        for (i = 0; i < num1; i++)
            for (j = 0; j < sum1; j++)
                c[i+j+1] += a[i] * b[j];//�ۼӸ���λ���ϵĳ˻�

        for (i = num1 + sum1 - 1; i > 0; i--)
            while (c[i] > 9)//ʮ����,�Mʮ��һ
            {
                c[i] -= 10;
                c[i-1] += 1;
            }
        if (c[0])//������λ����0�����c[0]
            printf("%d", c[0]);
        for (i = 1; i < num1 + sum1; i++)
        {
            printf("%d", c[i]);//����������������
            if ((i == num1 + sum1 - num2 - num2 - 1) && i != num1 + sum1 - 1)//�жϿ������С����
                printf(".");
        }
        printf("\n");//����
    }

    return 0;
}
