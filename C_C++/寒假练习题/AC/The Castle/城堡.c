#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAXN 51

static int m, n, area;
int mat[MAXN][MAXN];
int vis[MAXN][MAXN];

void dfs( int , int );

int main( void )
{
    int i, j;

    while ( scanf("%d%d", &m, &n ) != EOF )
    {
        memset( vis, 0, sizeof( vis ) );

        for ( i = 0; i < m; i++ )
            for ( j = 0; j < n; j++ )
                scanf("%d", &mat[i][j]);

        int room_max = 0, room_sum = 0;

        for ( i = 0; i < m; i++ )
            for ( j = 0; j < n; j++ )
                if ( !vis[i][j] )
                {
                    area = 0;

                    dfs( i, j );

                    if ( room_max < area )
                        room_max = area;
                    if ( area )
                        room_sum++;
                }
        printf("%d\n%d\n", room_sum, room_max);
    }

    return 0;
}
void dfs(int x, int y)
{
    if ( x < 0 || x >= m || y < 0 || y >= n )
        return ;
    int i, j;
    if ( !vis[x][y] )
    {
        for (i = 0; i < m; i ++)                /*跟随农民的走动*/
        {
            for (j = 0; j < n; j ++)
                printf("%d", vis[i][j]);
            puts("");
        }
        getchar();

        vis[x][y] = 1;
        area++;

        if ( mat[x][y] < 8 )
            dfs( x + 1, y );
        else
            mat[x][y] %= 8;

        if ( mat[x][y] < 4 )
            dfs( x, y + 1 );
        else
            mat[x][y] %= 4;

        if ( mat[x][y] < 2 )
            dfs( x - 1, y );
        else
            mat[x][y] %= 2;

        if ( mat[x][y] < 1 )
            dfs( x, y - 1 );

    }

    return ;
}
