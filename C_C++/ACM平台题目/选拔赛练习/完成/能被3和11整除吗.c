#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    char str[1001];//��������
    int n, z;

    scanf("%d\n", &n);//����������ݵ�����

    for (z = 1; z <= n; z++)
    {
        int i, sum, zonghe, oushu = 0, jishu = 0;//���岢��ʼ������
        gets(str);
        for (i = 0; i < strlen(str); i++)
        {
            if (i % 2 == 0)
                oushu += (str[i] - '0');//���ż��λ�ϵĺ�
            else
                jishu += (str[i] - '0');//�������λ�ϵĺ�
        }
        //printf("%d %d\n", oushu, jishu);

        zonghe = oushu + jishu;//��ĸ���λ���ϵĺ�
        sum = fabs(oushu - jishu);//�����λ����żλ��֮��ľ���ֵ

        printf("Case %d:\n", z);//��ʽ����
        if (zonghe % 3 == 0)//�ж��Ƿ��ܱ�3����
            printf("yes ");
        else
            printf("no ");

        if (sum % 11 == 0)//�����żλ��ľ���ֵ�ܱ�11���������ԭ�����ܱ�11����
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
