#include <stdio.h>
#define N 100

int a[N],end;//�����ⲿ����

void zuhe(int , int );//��m��Ԫ����ȡ��k��Ԫ�ص����

int main(void)
{
    int n,m;

    scanf("%d%d",&n,&m);
    end = m;
    zuhe(n, m);

    return 0;
}
void zuhe(int n,int m)//��m��Ԫ����ȡ��k��Ԫ�ص����
{
    int i, j;//�������

    for(i = 1; i <= n; i++)
    {
        a[m] = i;//���һ��λ�õ�Ԫ�ؿ���ȡm,m-1,m-2.....k

        if(m > 1)
            zuhe(i-1, m-1);//�ݹ����
        else
        {
            for(j = 1; j <= end; j++)
                printf((1 == j) ? "%d" : " %d",a[j]);
            printf("\n");
        }
    }
}
