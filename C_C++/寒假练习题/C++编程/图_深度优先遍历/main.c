#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAXN 40

static int mat[MAXN][MAXN], vis[MAXN];
static int m, n;

void DFS( int );

int main( void )
{
    int a, b;
    int i, j;

    scanf("%d%d", &m, &n );

    memset( mat, 0, sizeof( mat ) );
    memset( vis, 0, sizeof( vis ) );

    for ( i = 0; i < n; i++ ){
        scanf("%d%d", &a, &b );
        mat[a][b] = mat[b][a] = 1;
    }
    for ( i = 0; i < m; i++ ){
        for ( j = 0; j < m; j++ ){
            printf("%d ", mat[i][j] );
        }
        puts("");
    }

    for ( i = 0; i < m; i++ ){
        if ( !vis[i] ){
            DFS( i );
        }
    }

    return 0;
}
void DFS( int x )
{
    int i;

    vis[x] = 1;
    printf("%d ", x );

    for ( i = 0; i < m; i++ ){
        if ( !vis[i] && mat[x][i] ){
            DFS( i );
        }
    }

    return 0;
}
