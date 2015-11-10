#include <stdio.h>
#include <string.h>
#define  MAXN 1001

int main( void )
{
    char str[MAXN];
    int  i, j;

    while ( gets( str ) != NULL )
    {
        if ( 0 == strcmp( str, "@" ) )
            break;

        int len = strlen( str );
        int k, ok = 0;

        for ( k = 1; k < len - 1; k++ )
            if ( '&' == str[k] )
            {
                ok = 1;
                break;
            }
        if ( ok )
        {
            for ( i = 0, j = len - 1; i <= k; i++ )
                if ( str[i] != str[j--] )
                    break;
            if ( i >= k )
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
            printf("No\n");
    }

    return 0;
}
