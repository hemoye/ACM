#include <stdio.h>
#include <string.h>
#define  MAX 10000

int main( void )
{
    int i, j, n;

    while ( scanf("%d", &n) != EOF )
    {
        if ( 0 == n )
            break;
        int f[MAX] = {1};
        for ( i = 2; i <= n; i++ )
        {
            int c = 0;

            for ( j = 0; j < MAX; j++ )
            {
                int s = f[j] * i + c;
                f[j] = s % 10;
                c = s / 10;
            }
        }
        for ( j = MAX - 1; j >= 0; j-- )
            if ( f[j] )
                break;
        for ( i = j; i >= 0; i-- )
            printf("%d", f[i]);
        puts("");
    }

    return 0;
}
