#include <stdio.h>
#include <string.h>
#define MAX 200

int a[MAX][MAX];

int main(void)
{
    int i, j, k, n;
    char str[MAX];

    while ( scanf("%s", str) != EOF )
    {
        if ( str[0] >= '0' && str[0] <= '9' )
        {
            n = str[0] - '0';

            for ( i = 0; i < n; i++ )
                for ( j = 0; j < n; j++ )
                    scanf("%d", &a[i][j]);
        }
        else if ( !strcmp(str, "SHOW") )
        {
            for ( i = 0; i < n; i++ )
            {
                for ( j = 0; j < n; j++ )
                    printf( j ? " %d" : "%d", a[i][j] );
                puts("");
            }
            puts("");
        }
        else if ( !strcmp(str, "NEIGHBORS") )
        {
            int m, flage = 0;

            scanf("%d", &m);

            for ( i = 0; i < n; i++ )
                for ( j = 0; j < n; j++ )
                    if ( a[i][j] == m )
                    {
                        if ( i > 0 && ++flage )
                            printf("%d", a[i-1][j]);
                        if ( j > 0 )
                            printf( flage++ ? " %d" : "%d", a[i][j-1]);
                        if ( j < n - 1 )
                            printf( flage++ ? " %d" : "%d", a[i][j+1]);
                        if ( i < n - 1 )
                            printf( flage++ ? " %d" : "%d", a[i+1][j]);
                        puts("");
                    }
        }
    }
    return 0;
}
