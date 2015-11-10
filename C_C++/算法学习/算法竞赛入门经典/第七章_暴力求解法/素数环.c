#include <stdio.h>
#include <string.h>
#include <math.h>
#define  MAXN 40

int vis[MAXN];
int total;
int n;

void dfs( int );
int  is_prime( int );

int main( void )
{
    int i;

    while ( scanf("%d", &n ) != EOF )
    {
        total = 0;
        vis[0] = 1;

        dfs( 1 );
    }

    return 0;
}
void dfs( int cur )
{
    int i, j;

    if ( cur == n && is_prime( vis[0] + vis[n-1] ) )
    {
        total++;

        for ( i = 0; i < n; i++ )
            printf("%d ", vis[i]);
        puts("");

        return ;
    }
    for ( i = 1; i <= n; i++ )
    {
        int ok = 1;
        vis[cur] = i;

        if ( !is_prime( vis[cur] + vis[cur-1]) )
            ok = 0;

        for ( j = 0; j < cur && ok; j++ )
            if ( vis[cur] == vis[j] )
            {
                ok = 0;
                break;
            }
        if ( ok )
            dfs( cur + 1 );
    }
}
int is_prime( int m )
{
    int i;

    for ( i = 2; i <= sqrt( m ); i++ )
        if ( m % i == 0 )
            return 0;
    return 1;
}
