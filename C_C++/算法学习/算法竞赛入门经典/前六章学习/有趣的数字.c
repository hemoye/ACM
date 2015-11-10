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

    sprintf(str, "%d", x);//讲数字转化成字符串

    for ( i = 1; i < strlen(str); i++ )//按数字对应的ASCII值从大到小排列字符串
        for ( j = 0; j < strlen(str) - i; j++ )
            if ( str[j] < str[j+1] )
            {
                char ch = str[j];
                str[j] = str[j+1];
                str[j+1] = ch;
            }

    sscanf(str, "%d", &m);//将字符串转化成数字
    int temp = m, n = 0;

    while ( temp )//逆序取得数字
    {
        n = n * 10 + temp % 10;
        temp /= 10;
    }

    return fabs(m - n);//返回两个数字的差的绝对值
}
