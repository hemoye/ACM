#include <stdio.h>
#include <string.h>
#define  MAXN 10

char mat[MAXN][MAXN];
int  vis[MAXN][MAXN];
int n, k, sum;

void dfs( int , int , int );

int main( void )
{
    while ( scanf("%d%d", &n, &k) != EOF )
    {
        if ( -1 == n && -1 == k )
            break;

        int i, j, z;

        memset( vis, 0, sizeof( vis ) );

        for ( i = 0; i < n; i++ )
            scanf("%s", mat[i]);

        sum = 0;

        for ( i = 0; i < n; i++ )
            for ( j = 0; j < n; j++ )
                if ( !vis[i][j] && mat[i][j] == '#' )
                {
                    for ( z = 0; z < n; z++ )
                        vis[i][z] = 1;
                    dfs( i + 1, j, k - 1 );
                    for ( z = 0; z < n; z++ )
                        vis[i][z] = 0;
                }
        printf("%d\n", sum);
    }

    return 0;
}
void dfs( int x, int y, int z )
{
    if ( x < 0 || x > n || y < 0 || y >= n )
        return ;
    if ( z <= 0 )
    {
        sum++;
        return ;
    }

    int i, j, a;

    for ( i = x; i < n; i++ )
        for ( j = 0; j < n; j++ )
            if ( !vis[i-1][j] && mat[i][j] == '#' && j != y )
            {
                for ( a = 0; a < n; a++ )
                    vis[i][a] = 1;
                dfs( i + 1, j, z - 1 );
                for ( a = 0; a < n; a++ )
                    vis[i][a] = 0;
            }
}
