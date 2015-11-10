#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  MAXN 40

static int mat[MAXN][MAXN], vis[MAXN];
static int Q[MAXN];

void BFS( int n );

int main( void )
{
    int i, j;
    int a, b;
    int m, n;

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

    BFS( m );

    return 0;
}
void BFS( int n )
{
    int i, j;
    int front = 0, rear = 0;

    for ( i = 0; i < n; i++ ){
        if ( !vis[i] ){
            vis[i] = 1;
            Q[rear++] = i;
            printf("%d ", i );

            while ( front < rear ){
                i = Q[front++];

                for ( j = 0; j < n; j++ ){
                    if ( !vis[j] && mat[i][j] ){
                        vis[j] = 1;
                        Q[rear++] = j;
                        printf("%d ", j );
                    }
                }
            }
        }
    }
}
