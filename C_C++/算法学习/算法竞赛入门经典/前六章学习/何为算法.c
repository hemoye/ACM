#include <stdio.h>
#define  MAXN 100000

int main( void )
{
    int num, m, n, i;
    int arrAy[MAXN];

    while ( scanf("%d", &n) != EOF )
    {
        if ( n <=0 )
            break;

        arrAy[0] = 0;
        for ( i = 1; i <= n; i++ )
        {
            scanf("%d", &num );
            arrAy[i] = arrAy[i-1] + num;
        }
        scanf("%d", &num );
        for ( i = 0; i < num; i++ )
        {
            scanf("%d%d", &m, &n );
            printf("%d\n", arrAy[n] - arrAy[m-1] );
        }
    }

    return 0;
}
