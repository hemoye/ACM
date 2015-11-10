#include <stdio.h>
#include <string.h>
#include <math.h>
#define  MAX 5

int Judge( int );

int main( void )
{
    int m;
    int count = 0;

    scanf("%d", &m);

    printf("%d", m);
    while ( count != m )
    {
        count = m;
        m = Judge( m );
        printf("->%d", m);
    }
    puts("");

    return 0;
}
int Judge( int x )
{
    int i, j, m;
    char str[MAX];

    sprintf(str, "%d", x);//������ת�����ַ���

    for ( i = 1; i < strlen(str); i++ )//�����ֶ�Ӧ��ASCIIֵ�Ӵ�С�����ַ���
        for ( j = 0; j < strlen(str) - i; j++ )
            if ( str[j] < str[j+1] )
            {
                char ch = str[j];
                str[j] = str[j+1];
                str[j+1] = ch;
            }

    sscanf(str, "%d", &m);//���ַ���ת��������
    int temp = m, n = 0;

    while ( temp )//����ȡ������
    {
        n = n * 10 + temp % 10;
        temp /= 10;
    }

    return fabs(m - n);//�����������ֵĲ�ľ���ֵ
}
