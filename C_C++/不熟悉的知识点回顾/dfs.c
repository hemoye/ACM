#include <stdio.h>
#include <string.h>
#define  MAXN 40

int mat[MAXN][MAXN], vis[MAXN];
int m, n;

void dfs( int );

int main( void )
{
    int a, b, i, j;

    #ifndef LOCAL
        freopen( "dfs.txt", "r", stdin );
        freopen( "dfs.OUT", "a+", stdout );
    #endif

    while ( scanf("%d%d", &m, &n ) != EOF )
    {
        memset( mat, 0, sizeof( mat ) );
        memset( vis, 0, sizeof( vis ) );

        for ( i = 0; i < n; i++ )
        {
            scanf("%d%d", &a, &b);
            mat[a][b] = mat[b][a] = 1;
        }

        for ( i = 0; i < m; i++ )
        {
            for ( j = 0; j < m; j++ )
                printf("%d ", mat[i][j] );
            puts("");
        }
        for ( i = 0; i < m; i++ )
            if ( !vis[i] )
            {
                printf("%d ", i );
                vis[i] = 1;
                dfs( i );
            }
        puts("");
    }

    return 0;
}
void dfs( int x )
{
    if ( x < 0 || x >= m )
        return ;

    int i;

    for ( i = 0; i < m; i++ )
        if ( !vis[i] && mat[x][i] )
        {
            printf("%d ", i );
            vis[i] = 1;
            dfs( i );
        }
}
