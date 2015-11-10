#include <stdio.h>

void Anwser( int );
int  Min_Time( int , int );

int main( void )
{
    int n;

    while ( scanf("%d", &n) != EOF )
        Anwser( n );

    return 0;
}
void Anwser( int n )
{
    int i, j;
    int temp;

    for ( i = n + 1; i <= 2 * n; i++ )
    {
        temp = i * n;

        if ( !( temp % ( i - n ) ) )
            printf("1/%d = 1/%d + 1/%d\n", n, temp / Min_Time( i, n ), i );
    }

    return ;
}
/*******求最大公约数函数*******/
int Min_Time( int m, int n )
{
    int temp = m;

    while ( temp )
    {
        temp = m % n;
        m = n;
        n = temp;
    }

    return m;
}
