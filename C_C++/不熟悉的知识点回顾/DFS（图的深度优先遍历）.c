#include <stdio.h>
#define  MAX 40

static int mat[MAX][MAX], vis[MAX];
static int m, n;

void dfs( int x );

int main( void )
{
    int i, j;

    while ( scanf("%d%d", &m, &n) != EOF ){
        int a, b;

        for ( i = 0; i < n; i++ ){
            scanf("%d%d", &a, &b);
            mat[a][b] = mat[b][a] = 1;
        }

        for ( i = 0; i < m; i++ ){
            for ( j = 0; j < m; j++ ){
                printf("%d ", mat[i][j]);
            }
            puts("");
        }

        for ( i = 0; i < m; i++ ){
            if ( !vis[i] ){
                dfs( i );
            }
        }
    }

    return 0;
}
void dfs( int x )
{
    int i;

    printf("%d ", x);
    vis[x] = 1;

    for ( i = 0; i < m; i++ ){
        if ( !vis[i] && mat[x][i] ){
            dfs( i );
        }
    }

    return ;
}
