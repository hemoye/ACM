#include <iostream>
#include <cstring>
#define  MAXN 20

using namespace std;

int n, m, Max;
int arrAy[MAXN][MAXN];
int vis[MAXN][MAXN];

void dfs( int , int );

int main( void )
{
    while ( cin >> n ){
        Max = 0;
        for ( int i = 1; i <= n; i++ ){
            for ( int j = 1; j <= n; j++ ){
                cin >> arrAy[i][j];
            }
        }
        for ( int i = 0; i <= n + 1; i++ ){
            arrAy[i][0] = 0;
            arrAy[0][i] = 0;
            arrAy[n+1][i] = 0;
            arrAy[i][n+1] = 0;
        }
        for ( int i = 1; i <= n; i++ ){
            for ( int j = 1; j <= n; j++ ){
                m = 0;
                memset( vis, 0, sizeof( vis ) );
                dfs( i, j );
                if ( Max < m ){
                    Max = m;
                }
            }
        }
        cout << Max << endl;
    }

    return 0;
}
void dfs( int x, int y )
{
    if ( x < 1 || x > n || y < 1 || y > n ){
        if ( Max < m ){
            Max = m;
        }
        memset( vis, 0, sizeof( vis ) );
        return ;
    }
    for ( int i = 1; i <= n; i++ ){
        for ( int j = 1; j <= n; j++ ){
            if ( !vis[i][j] ){
                m += arrAy[i][j];
                vis[i][j] = vis[i+1][j] = vis[i-1][j] = vis[i][j+1] = vis[i][j-1] = 1;
                dfs( i, j );
            }
        }
    }
}
