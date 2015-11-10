#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( void )
{
    int i, j, m;

    while ( scanf("%d", &m ) != EOF )
    {
        int ok = 1;

        for ( i = 2; i < m; i++ )
        {
            if ( 0 == m % i )
            {
                if ( 2 == i || 3 == i || 5 == i )
                {
                    m /= i;
                    i = 2;
                }
                else
                {
                    ok = 0;
                    break;
                }
            }
        }
        if ( ok && m <= 5 )
            printf("Yes\n");
        else
            printf("No\n");
    }
}
