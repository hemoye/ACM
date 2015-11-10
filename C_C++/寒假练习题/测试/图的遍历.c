#include <stdio.h>
#include <stdlib.h>
#define  MAXN 40

int hang, lie, count;
char mat[MAXN][MAXN];
int  vis[MAXN][MAXN];

void bfs( int , int );

int main( void )
{
    int i, j;

    while ( scanf("%d%d", &lie, &hang ), hang || lie )
    {
        int ok = 1;
        count = 0;
        memset( vis, 0, sizeof( vis ) );

        for ( i = 0; i < hang; i++ )
            scanf("%s", mat[i] );
        for ( i = 0; i < hang; i++ )
        {
            for ( j = 0; j < lie; j++ )
                if ( 'S' == mat[i][j] )
                {
                    ok = 0;
                    break;
                }
                if ( 0 == ok )
                    break;
        }
        mat[i][j] = '.';
        bfs( i, j );

        if ( count )
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
void bfs( int x, int y )
{
    if ( x < 0 || x >= hang || y < 0 || y >= lie )
        return ;
    if ( 'P' == mat[x][y] )
    {
        count++;
        return ;
    }
    if ( '.' == mat[x][y] && !vis[x][y] )
    {
        vis[x][y] = 1;
        bfs( x + 1, y );
        bfs( x - 1, y );
        bfs( x, y + 1 );
        bfs( x, y - 1 );
    }
}
