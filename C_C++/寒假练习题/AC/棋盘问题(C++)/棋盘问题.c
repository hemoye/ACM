#include <stdio.h>
#include <string.h>
#define MAXN 10

char mat[MAXN][MAXN];
int vis[MAXN];
int n, sum;

void dfs( int x, int q )
{
    if ( q <= 0 )
    {
        sum++;
        return ;
    }
    if ( x < 0 || x >= n )
        return ;

    int i;

    for ( i = 0; i < n; i++ )
        if( !vis[i] && mat[x][i] == '#' )
        {
            vis[i] = 1;
            dfs( x + 1, q - 1 );
            vis[i] = 0;
        }
    dfs( x + 1, q );
}
int main(void)
{
    int k;

    while ( scanf("%d%d", &n, &k ) != EOF )
    {
        if ( n == -1 && k == -1 )
            break;

        memset(vis, 0, sizeof(vis));
        sum = 0;

        int i;
        for (i = 0; i < n; i ++)
            scanf("%s", mat[i]);

        dfs( 0, k );

        printf("%d\n", sum);
    }
    return 0;
}
