#include <stdio.h>
int main(void)
{
    int n, k;//�������

    scanf("%d", &n);//����Ҫ������ִ�С
    for (k = 2; k < n; )//ѭ���ж�
    {
        if (n % k != 0)//���n%k������0��k����n����������k�Լ�
            k++;
        else
        {
            n /= k;
            printf("%d ", k);//���������
            k = 2;
        }
    }
    printf("%d", k);//������һ��������

    return 0;
}
