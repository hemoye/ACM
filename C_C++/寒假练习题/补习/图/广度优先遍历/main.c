#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  MAXN 100

char mat[MAXN][MAXN];
int  vis[MAXN][MAXN];
int  m, n;
int  step, count;

void bfs( int x, int y );

int main( void )
{
    int start;
    int i, j;

    /*freopen( "test.txt", "r", stdin );*/

    while ( scanf("%d%d", &m, &n ) != EOF )
    {
        if ( 0 == m && 0 == n )
            break;

        step = count = 0;
        memset( vis, 0, sizeof( vis ) );
        scanf("%d", &start );

        for ( i = 0; i < m; i++ )
            scanf("%s", &mat[i] );

        bfs( 0, start - 1 );
    }

    return 0;
}
void bfs( int x, int y )
{
    if ( x < 0 || x >= m || y < 0 || y >= n )
    {
        printf("%d step(s) to exit\n", step );
        return ;
    }

    vis[x][y]++;
    if ( 1 == vis[x][y] )
        step++;
    else if ( 2 == vis[x][y] )
        count++;
    else
    {
        printf("%d step(s) before a loop of %d step(s)\n", step - count, count );
        return ;
    }

    if ( 'E' == mat[x][y] )
        bfs( x, y + 1 );
    else if ( 'W' == mat[x][y] )
        bfs( x, y - 1 );
    else if ( 'N' == mat[x][y] )
        bfs( x - 1, y );
    else if ( 'S' == mat[x][y] )
        bfs( x + 1, y );
}
