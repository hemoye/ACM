#include <stdio.h>
#include <string.h>//Ϊ�ַ������ṩԭ��

int main(void)
{
    int dachengfa(char * , char * , int );

    unsigned m, n;//������䣬���������޷������α���

    scanf ("%u", &m);//����������ݵ�����
    for (n = 0; n < m; n++)//���Ʋ������ݵ�����
    {
        char str1[1000], str2[1000];//��������һά�ַ�����
        int a[100] = {0}, b[100] = {0}, c[1000] = {0};//���岢��ʼ������һά����
        int i, j, x, y, len, z = 0;//�������

        scanf("%s%s", str1, str2);//��������ַ���
        if (strcmp (str1, str2) == 0)//������������ڳ���
        {
            printf("1\n");//�����1�������������ж�
            continue;
        }
        else if (strcmp (str1, str2) < 0)//������������ڳ���
        {
            printf("0\n");//�����0�������������ж�
            continue;
        }
        else
        {
            len = strlen(str1) - strlen(str2);
            for (i = 0; i < strlen(str1); i++)//�ѳ����������ַ�ת�������ֲ���������
                a[i] = str1[i] - '0';
            for (i = 0; i < strlen(str2); i++)//�ѱ������������ַ�ת�������ֲ���������
                b[i] = str2[i] - '0';
            for (i = 0; i < len; i++)
            {
                if ()
            }
    }

    return 0;
}
int dachengfa(char * a, char * b; int len, int z)
{
    int i = z;
    int j, t;

    for (t = 1; t <= 9; t++)
    {

    }
}
