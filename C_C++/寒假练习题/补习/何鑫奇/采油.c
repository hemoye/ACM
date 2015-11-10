#include <stdio.h>
#include <string.h>
#define  MAXN 100

int m, n;
char mat[MAXN][MAXN];
int  vis[MAXN][MAXN];

void bfs( int , int );

int main( void )
{
    int i, j;
    int sum;

    while ( scanf("%d%d", &m, &n ) != EOF )
    {
        if ( 0 == m && 0 == n )
            break;

        sum = 0;
        memset( vis, 0, sizeof( vis ) );

        for ( i = 0; i < m; i++ )
            scanf("%s", mat[i] );
        for ( i = 0; i < m; i++ )
            for ( j = 0; j < n; j++ )
                if ( !vis[i][j] && '@' == mat[i][j] )
                {
                    sum++;
                    bfs( i, j );
                }
        printf("%d\n", sum );
    }

    return 0;
}
void bfs( int x, int y )
{
    if ( x < 0 || x >= m || y < 0 || y >= n )
        return ;
    else if ( '*'  == mat[x][y] || vis[x][y] )
        return ;

    vis[x][y] = 1;
    bfs( x, y + 1 );
    bfs( x, y - 1 );
    bfs( x - 1, y );
    bfs( x + 1, y );
    bfs( x - 1, y + 1 );
    bfs( x - 1, y - 1 );
    bfs( x + 1, y - 1 );
    bfs( x + 1, y + 1 );
}
