//2013年1月11日 12:52:58
//功能：求表达式1-2+3-4+5-......+n的值
//目的：验证代码的效率、成果

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
/*总结:代码的简洁性、与时间的复杂度相比较*/
