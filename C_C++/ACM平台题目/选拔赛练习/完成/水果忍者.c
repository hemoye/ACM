#include <stdio.h>

int main(void)
{
    void function(int * str, int * n);//��������

    int i, j, n, t, T, str[1000];//�������

    scanf("%d", &T);//����������ݵ�����
    for (t = 0; t < T; t++)
    {
        scanf("%d", &n);//����ÿһ��������������ֵĸ���

        for (i = 0; i < n; i++)
            scanf("%d", &str[i]);//����һά����

        printf("Case #%d:\n", t+1);

        function(str, n);//���ú���
    }

    return 0;
}
void function(int * str, int * n)
{
    int num, i, j, t, x, flage;//�������
    int str1[1000];

    if (n < 3)//�ж�  ������鳤��С��3��ֱ�����0
        printf("0\n");
    else
    {
        for (i = x = 0; i < n; i++)//ȥ����������ͬ��Ԫ��
        {
            flage = 1;
            for (j = 0; j < i; j++)
                if (str[i] == str[j])
                    flage = 0;
            if (flage)
                str1[x++] = str[i];
        }

        for (i = num = 0; i < x; i++)
            for (j = i+1; j < x; j++)//����ѭ���ж�
                for (t = j+1; t < x; t++)
                    if ((str1[i] != str1[j]) && (str1[i] != str1[t]) && (str1[t]) != str1[j])
                        num++;
        printf("%d\n", num);//���������ĿҪ�����ϸ���
    }
}
