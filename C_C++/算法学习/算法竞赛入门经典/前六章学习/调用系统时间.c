#include <stdio.h>
#include <time.h>

int main( void )
{
    long long n;
    int count = 0;

    scanf("%f", &n);

    while ( n > 1 )
    {
        if ( n % 2 )
            n = n * 3 + 1;
        else
            n /= 2;
        count++;
    }

    printf("%d\n", count);
    printf("Time used = %lf", (double)clock() / CLOCKS_PER_SEC);
    //该语句功能：测试并输出系统使用的时间

    return 0;
}
