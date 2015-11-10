#include <cstdio>

int Dj( int );

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
    freopen( "test.out", "w", stdout );
#endif
    int n;
    while ( scanf("%d", &n ) != EOF ){
        printf("%d\n", Dj( n ) );
    }

    return 0;
}
int Dj( int n )
{
    return ( 1 == n ) ? 1 : Dj( n / 2 ) + 1;
}
