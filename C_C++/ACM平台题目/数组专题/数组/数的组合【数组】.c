#include <stdio.h>

int a[50];

void swap(int * a, int * b, int t)//�����������ݵ�ֵ
{
    t = *a;
    *a = *b;
    *b = t;
}

void search(int n, int pos, int m)
{
    int i, t;

    if(pos < 0)//��Ϊ�����ݹ���ж���־
        return ;

    swap(&a[pos], &a[n-m], t);//���������ڲ���ֵ

    for(i=n-1; i>=pos; i--)
        printf("%d", a[i]);//��ӡÿһ������
    if (pos != 0)
        printf("��");
    swap(&a[n-m], &a[pos], t);//�����ݽ�������
    m++;
    if(0 == n - m + 1)//�ж��ǲ����Ѿ���������mλ��
        search(n-1, pos-1, n-pos);
    else
        search(n, pos, m);
}
int main(void)
{
    int i, m;

    for(i=0; i<6; i++)
        scanf("%d", &a[i]);//���������е�ֵ

    scanf("%d", &m);//����ÿһ�����ݵ����ָ���

    search(6, 6 - m, m);//��������

    return 0;
}

