#include <cstdio>

int dp( int n, int m )
{
    if ( n < 1 || m < 1 )   return 0;
    if ( 1 == n )   return 1;
    if ( n < m )    return dp( n, n );
    if ( n == m )   return dp( n, m - 1 ) + 1;
    return dp( n, m - 1 ) + dp( n - m, m );
}
int main( int agrc, char *agrv[] )
{
    int n, m;
    while ( ~scanf("%d", &n ) ){
        printf("%d\n", dp( n, n ) );
    }

    return 0;
}
