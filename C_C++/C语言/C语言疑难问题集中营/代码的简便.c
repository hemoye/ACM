//2013��1��11�� 12:52:58
//���ܣ�����ʽ1-2+3-4+5-......+n��ֵ
//Ŀ�ģ���֤�����Ч�ʡ��ɹ�

#include <stdio.h>

long sum(int n)
{
    if ( n % 2 )
        return (n / 2) * (-1) + n;
    else
        return (n / 2) * (-1) + n;
}

int main( void )
{
    int n;

    scanf ("%d", &n);

    printf("%ld\n", sum(n));

    return 0;
}
/*�ܽ�:����ļ���ԡ���ʱ��ĸ��Ӷ���Ƚ�*/
