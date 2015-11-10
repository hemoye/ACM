#include <stdio.h>
#include <stdlib.h>
#define  MAXN 40

int n, total = 0;
int vis[MAXN];

void Search( int );

int main( void )
{
    while ( scanf("%d", &n) != EOF )
    {
        total = 0;
        Search( 0 );
        printf("%d\n", total );
    }

    return 0;
}
void Search( int cur )
{
    if ( cur == n )
    {
        total++;
        return ;
    }

    int i, j;

    for ( i = 0; i < n; i++ )
    {
        int ok = 1;
        vis[cur] = i;

        for ( j = 0; j < cur; j++ )
            if ( vis[cur] == vis[j] || cur - vis[cur] == j - vis[j] || cur + vis[cur] == j + vis[j] )
            {
                ok = 0;
                break;
            }
        if ( ok )
            Search( cur + 1 );
    }
}
