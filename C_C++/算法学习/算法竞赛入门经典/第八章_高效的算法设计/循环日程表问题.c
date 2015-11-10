#include <stdio.h>
#include <string.h>
#define  MAXN 40

static int arrAy[MAXN][MAXN];
void Table( int n );

int main( void )
{
    int i, j, n;

    while ( scanf("%d", &n ) != EOF )
    {
        if ( 0 == n )
            break;

        memset( arrAy, 0, sizeof( arrAy ) );
        Table( n );
        for ( i = 0; i < n; i++ )
        {
            for ( j = 0; j < n; j++ )
                printf("%d ", arrAy[i][j] );
            puts("");
        }
    }

    return 0;
}
void Table( int n )
{
    if ( 1 == n )
        arrAy[0][0] = 1;
    else
    {
        int i, j;
        int m = n / 2;

        Table( m );

        for ( i = 0; i < m; i++ )
            for ( j = m; j < 2 * m; j++ )
                arrAy[i][j] = arrAy[i][j-m] + m;
        for ( i = m; i < 2 * m; i++ )
            for ( j = 0; j < m; j++ )
                arrAy[i][j] = arrAy[i-m][j] + m;
        for ( i = m; i < 2 * m; i++ )
            for ( j = m; j < 2 * m; j++ )
                arrAy[i][j] = arrAy[i-m][j-m];
    }
    return ;
}
