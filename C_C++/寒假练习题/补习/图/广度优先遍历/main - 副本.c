#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  MAXN 100

char mat[MAXN][MAXN];
int  vis[MAXN][MAXN];
int  m, n;
int  step, nend, xx;

int  bfs( int x, int y );
void end( int x, int y );

int main( void )
{
    int start;
    int i, j;

    /*freopen( "test.txt", "r", stdin );*/

    while ( scanf("%d%d", &m, &n ) != EOF )
    {
        if ( 0 == m && 0 == n )
            break;

        step = nend = xx = 0;
        memset( vis, 0, sizeof( vis ) );
        scanf("%d", &start );

        for ( i = 0; i < m; i++ )
            scanf("%s", &mat[i] );

        nend = bfs( 0, start - 1 );
        if ( 0 == nend )
            printf("%d step(s) to exit\n", step );
        else
        {
            end( 0, start - 1 );
            printf("%d step(s) before a loop of %d step(s)\n", xx, step - xx - 1 );
        }
    }

    return 0;
}
int  bfs( int x, int y )
{
    if ( x < 0 || x >= m || y < 0 || y >= n )
            return 0;
    step++;

    if ( 'E' == mat[x][y] && !vis[x][y] )
    {
        vis[x][y] = 1;
        bfs( x, y + 1 );
    }
    else if ( 'W' == mat[x][y] && !vis[x][y] )
    {
        vis[x][y] = 1;
        bfs( x, y - 1 );
    }
    else if ( 'N' == mat[x][y] && !vis[x][y] )
    {
        vis[x][y] = 1;
        bfs( x - 1, y );
    }
    else if ( 'S' == mat[x][y] && !vis[x][y] )
    {
        vis[x][y] = 1;
        bfs( x + 1, y );
    }
    else
        return m * x + y;
}
void end( int x, int y )
{
    if ( x * m + y == nend )
        return ;

    xx++;
    if ( 'E' == mat[x][y] )
        end( x, y + 1 );
    else if ( 'W' == mat[x][y] )
        end( x, y - 1 );
    else if ( 'N' == mat[x][y] )
        end( x - 1, y );
    else
        end( x + 1, y );
}
