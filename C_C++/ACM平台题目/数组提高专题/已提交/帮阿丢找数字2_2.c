#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000];//����һ���ַ�����
    int z = 0;//���ڿ����������

    while (gets(str) != NULL)//�ַ�������������
    {
        int i, j, a[1000] = {0};//���岢��ʼ������

        for (i = j = 0; i < strlen(str); i++)//��ȡ��ת���ַ����ڲ�������
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                a[j] = a[j] * 10 + (str[i] - '0');//���ַ�������ת����������������
                if (!(str[i+1] >= '0' && str[i+1] <= '9'))//���ۼ�����Ӵ������ַ����е����һ��ֵ֮������������һλ
                    j++;
            }
        }
        printf("Case #%d:\n", ++z);//���Ƹ�ʽ
        for (i = 0; i < j; i++)
            printf((0 == i) ? "%d" : " %d", a[i]);//��������е�����
        printf("\n");
    }

    return 0;
}
