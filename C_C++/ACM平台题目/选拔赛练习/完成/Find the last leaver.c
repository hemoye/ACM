#include <stdio.h>
#include <string.h>

int main(void)
{
    void jiaohuan(char * str,  char * ch);//���庯��

    int n, i, j, t = 0;//��������

    while(scanf("%d", &n) != EOF)//��������
    {
        char str[2*n][1001];//��������
        int temp, time[2*n][2], shijian[2*n];

        for (i = 0; i < 2 * n; i++)
        {
            scanf("%s %d:%d", str[i], &time[i][0], &time[i][1]);//ѭ����������ѧ���Ľ���ʱ����뿪ʱ��
            shijian[i] = time[i][0] * 60 + time[i][1];//�÷��ӱ�ʾͬѧ������뿪���ҵ�ʱ��
        }

        printf("Case #%d:\n", ++t);//�����ʽ����

        for (i = 0; i < 2 * n - 1; i++)//��ʱ���������
            for (j = 0; j < 2 * n - i - 1; j++)
                if (shijian[j] > shijian[j+1])
                {
                    temp = shijian[j];
                    shijian[j] = shijian[j+1];
                    shijian[j+1] = temp;

                    jiaohuan(str[j], str[j+1]);//�ַ�����λ�ø���ʱ��ı䶯���䶯
                }

        printf("%s\n%s\n%d\n", str[0], str[2*n-1], shijian[2*n-1] - shijian[0]);//������
    }

    return 0;
}
void jiaohuan(char * str,  char * ch)//���庯��
//�������ܣ����������ַ���
{
    char * c[1001];

    strcpy(c, str);
    strcpy(str, ch);
    strcpy(ch, c);
}
