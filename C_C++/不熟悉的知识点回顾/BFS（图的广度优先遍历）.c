#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  MAX 40

static int mat[MAX][MAX], vis[MAX];
static int Q[MAX];

void bfs( int n );

int main( void )
{
    int m, n;

    memset( mat, 0, sizeof( mat ) );
    memset( vis, 0, sizeof( vis ) );

    while ( scanf("%d%d", &m, &n) != EOF ){
        int a, b;
        int i, j;

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
    bfs( m );
    puts("");
    }

    return 0;
}
void bfs( int n )
{
    int i, j;
    int front = 0, rear = 0;

    for ( i = 0; i < n; i++ ){
        if ( !vis[i] ){
            vis[i] = 1;
            printf("%d ", i);
            Q[rear++] = i;

            while ( front < rear ){
                i = Q[front++];

                for ( j = 0; j < n; j++ ){
                    if ( !vis[j] && mat[i][j] ){
                        vis[j] = 1;
                        printf("%d ", j);
                        Q[rear++] = j;
                    }
                }
            }
        }
    }

    return ;
}
