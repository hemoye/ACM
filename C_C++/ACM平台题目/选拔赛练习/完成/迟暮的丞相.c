/*#include <stdio.h>
#include <string.h>

int main(void)
{
    int sum, t;

    scanf("%d", &sum);//����������ݵ�����
    for (t = 1; t <= sum; t++)
    {
        int n, i, j, zt[3], yanse[3], daxiao[3];//��������
        int flage = 1;//��ʶ��

        scanf("%d", &n);//����˾��ܲ״̬����Ŀ
        for (i = 0; i < n; i++)
            scanf("%d", &zt[i]);//����˾��ܲ��״̬

        for (i = 0; i < 3; i++)//����������ܹ��������ƵĴ�С�Լ���ɫ
            scanf("%d %d", &daxiao[i], &yanse[i]);

        printf("Case %d: ", t);//��ʽ����

        if (zt[0] != 3)//���˾��ܲ�ĵ�һ��״̬��������
        {
            printf("����˾��ܲ���������! ");//�����������䲢������������
            continue;
        }
        else//���˾��ܲ�ĵ�һ��״̬������������ж�
        {
            for (i = 0; i < 3; i++)
                if (yanse[i] == 4 && (daxiao[i] >= 2 && daxiao[i] <= 9))//��������������3��������һ���Ǻ���2~9
                {
                    flage = 0;//���־Ϊ0
                    printf("�������������˾��ܲ! ");//������������
                }
            if (flage)//�����־��Ϊ0��������������
                printf("����˾��ܲ���������! ");
        }
        for (i = 0; i < n; i++)
            if (zt[i] == 3)
               printf("%d\n", i + 1);
    }

    return 0;
}
*/
#include <stdio.h>

int main(void)
{
    int sum, n, i, t, m;
    int a[3], b[6];
    scanf("%d", &sum);
    for (m = 1; m <= sum; m++)
    {
        int flage=0;
        scanf("%d", &n);
        for(i=0; i<n; i++)
            scanf("%d", &a[i]);
        if(n==1)
            flage=1;
        else if(n==2||n==3)
        {
            if(a[0]==3)
                flage=1;
        }
        for(i=0; i<6; i++)
            scanf("%d", &b[i]);
        if(flage==1)
        {
            for(i=0; i<6; i++)
                if((i+1)%2==0&&b[i]==4&&(b[i-1]>=2&&b[i-1]<=9))
                {
                    printf("Case %d: �������������˾��ܲ! ", m);
                    flage = 0;
                }
            if (flage)
                printf("Case %d: ����˾��ܲ���������! ", m);
        }
        else
            printf("Case %d: ����˾��ܲ���������! ", m);
        for(i=0; i<n; i++)
            if(a[i]==3)
                printf("%d\n", i+1);
    }
    return 0;
}
