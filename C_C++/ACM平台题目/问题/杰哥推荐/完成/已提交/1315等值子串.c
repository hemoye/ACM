#include <stdio.h>
#include <string.h>//�ṩstrlen����

int main(void)
{
    int i, j, x, y, z, num[10];
    char c, ch[10], str[4906];

    gets(str);//��ȡ�ַ���

    for (i = 0; i < 10; i++)
        num[i] = 1;//�������е�ÿһ��ֵ����Ϊ1

    x = y = 0;
    for (i = 0; i < strlen(str); i++)//���ַ������д���
    {
        z = 1;//��ʼ����ʶ��z��ֵ
        while (str[i] == str[i+1])
        {
            ch[x] = str[i];//�ѵ�һ�γ��ֵ���ͬ�ַ������ַ�����ĵ�һ��λ��
            num[x]++;//��ʾ��ͬ�ַ�������
            i++;
            z = 0;//�ı��ʶ����ֵ
        }
        if (z == 0)//�жϱ�ʶ���Ƿ�ı䣬����ı���ִ���ڲ����
        {
            x++;
            i--;
        }
    }
    for (i = 0; i < x - 1; i++)//ð�ݷ���������
        for (j = 0; j < x - 1 - i; j++)
            if (num[j] < num[j+1])
            {
                y = num[j];//�Ѵ����ֵ���ڵ�һ��λ��
                num[j] = num[j+1];
                num[j+1] = y;

                c = ch[j];//���ͬʱ�ַ���λ��Ҳ���ű䶯
                ch[j] = ch[j+1];
                ch[j+1] = c;
            }
    for (i = 0; i < num[0]; i++)//�����ĵ�ֵ�Ӵ�
        printf("%c", ch[0]);
    printf("\n");

    return 0;
}
