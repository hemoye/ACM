#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1001];
    int i, j, t, num, sum, T;

    scanf("%d", &T);//���Ʋ������ݵ�����
    for (t = 1; t <= T; t++)
    {
        scanf("%s", str);//��ö����������ַ���
        for (i = strlen(str) - 1, j = sum = 0; i >= 0; i--)//�����ۼ�
        {
            num = 1;//��ʼ������
            for (j = 0; j < strlen(str) - 1 - i; j++)
                num *= 2;
            sum += (num * (str[i] - '0'));//������ת��Ϊʮ����
        }
        printf("Case %d: %X\n", t, sum);//ʮ���������Զ����Ƶ���ʽ���
    }

    return 0;
}
