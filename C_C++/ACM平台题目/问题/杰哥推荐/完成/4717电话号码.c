#include <stdio.h>
#include <string.h>

int main(void)
{
    int judge(char str1[], char str2[]);

    int flage;
    unsigned i, j, t, m, n;//�������ַ���
    char str[100][20], ch[20];//����һ����ά�ַ���

    scanf("%d", &t);//����ѭ���Ĵ���
    for (m = 0; m < t; m++)
    {
        flage = 1;//��ʶ��
        scanf("%d", &n);//����绰����ĸ���
        for (i = 0; i < n; i++)
            scanf("%s", str[i]);//��õ绰����

        for (i = 0; i < n - 1; i++)//ѭ���жϵ绰�����Ƿ�Ϸ�
        {
            for (j = i + 1; j < n; j++)
                if (0 == judge(str[i], str[j]))//ѭ�����ú���
                {
                    flage = 0;//�ı��ʶ����ֵ
                    break;
                }
            if (0 == flage)//�����ʶ��Ϊ0��ֱ����������ѭ��
                break;
        }
        printf((0 == flage) ? "NO\n" : "YES\n");//�����ʶ��Ϊ0�����NO,�������YES
    }

    return 0;
}
int judge(char str1[], char str2[])//���庯���ж������ַ����г��ȶ̵��ַ����볤���ַ���ǰ�沿���Ƿ���ͬ
{
    int len, i, j;//�������
    char str[20];//����һ���ַ�������

    len = (strlen(str1) > strlen(str2)) ? strlen(str2) : strlen(str1);//���ַ������ȶ̵��ַ������ȸ���len

    if (strlen(str1) < strlen(str2))//���ַ����ȶ̵��ַ�������str1
    {
        strcpy (str, str2);
        strcpy (str2, str1);
        strcpy (str1, str);
    }

    for (i = 0; i < len - 1; i++)
        if (str1[i] != str2[i])//����в���ͬ���ַ�����ֹ���򲢷�������1���������ѭ��
            return 1;

    return 0;//����ܹ����ѭ������������ַ�����ǰlen���ַ���ȫ��ͬ������ֹ���򲢷�������0
}
