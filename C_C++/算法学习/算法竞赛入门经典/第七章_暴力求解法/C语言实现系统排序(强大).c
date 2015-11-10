#include <stdio.h>
#include <stdlib.h>
#define  MAXN 10

int cmp( const void * p, const void * q )
{
    return * ( int * ) p - * ( int * ) q;
}

int main( void )
{
    int i, n;
    int arrAy[MAXN];

    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        scanf("%d", &arrAy[i]);

    qsort( arrAy, n, sizeof( arrAy[0] ), cmp );

    for ( i = 0; i < n; i++ )
        printf("%d ", arrAy[i]);
    puts("");

    return 0;
}
