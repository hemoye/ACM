#include <stdio.h>

int main(void)
{
    int Judge(unsigned char str[]);//��������
    int judge(int a);

    unsigned char str[30];//����һ�����鳤��Ϊ30���ַ�������

    while (gets (str) != NULL)//���������ַ���
        printf(Judge(str) ? "Y\n" : "N\n");//���ú���Judge���ж�

    return 0;
}

int Judge(unsigned char str[])//���캯��
{
    int i, j, k;//��������
    int sum[4] = {0};//����һ��4��4�еĶ�ά��
    for (i = j = k = 0; i < strlen(str); i++)//��ȡstr�ַ�������������ַ�
    {
        if (str[i] == '.')//��������.���н����ַ�
        {
            printf("%d ", sum[j]);
            j++;
            k = 0;
        }
        else
            sum[j] = sum[j] * 10 + (int)(str[i]);//���ַ������ά��������
    }
    for (i = 0; i < 4; i++)
    {
        if (judge(sum[i]) == 0)//���ú����ж�ÿһ���ַ����Ƿ����IP��ַ�Ĺ涨
            break;
    }
    if (i == 4)//���i�ܹ��ۼ���4����˵��IP��ַ�Ϸ�����������1
        return 1;
    else
        return 0;
}
int judge(int a)//���庯���ж��ַ���
{

    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
        return 0;
    else
        return 1;
}
