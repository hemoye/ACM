#include <stdio.h>

void maopao(int * , int );//��������

int main(void)//������
{
    int n, i, j, num;//�������

    while (scanf("%d", &n) != EOF)//������ƥ����
    {
        if (0 == n)
            break;
        int ziyuan[n], duishou[n];//�����������鳤��Ϊn������

        for (i = 0; i < n; i++)
            scanf("%d", &ziyuan[i]);//������Ԩ����ƥ�ٶ�
        for (i = 0; i < n; i++)
            scanf("%d", &duishou[i]);//������ֵ���ƥ�ٶ�

        maopao(ziyuan, n);//���ú���
        maopao(duishou, n);//���ú���

        for (i = j = num = 0; i < n; i++)//�𽥱Ƚ���Ԩ����ֵ���ƥ�ٶ�
            if (ziyuan[i] > duishou[j])//�����Ԩ����ƥ�ٶȴ��ڶ��ֵ���ƥ�ٶ�
            {
                j++;                   //��Ƚ϶����ٶȱ�ǰһƥ�����
                num++;                 //����num�Լ�
            }

        printf((num > n / 2) ? "YES\n" : "NO\n");//�жϲ������Ԩ����Ӯ���
    }

    return 0;
}

void maopao(int * pArr, int n)//���庯��ð�ݷ��������������
{
    int i, j, t;//�������

    for (i = 0; i < n - 1; i++)//ð�ݷ�����
        for (j = 0; j < n - i - 1; j++)
            if (pArr[j] > pArr[j+1])//���ǰһ���ֵ���ں�һ���ֵ���򽻻����ߵ�ֵ
            {
                t = pArr[j];
                pArr[j] = pArr[j+1];
                pArr[j+1] = t;
            }

    return 0;
}
