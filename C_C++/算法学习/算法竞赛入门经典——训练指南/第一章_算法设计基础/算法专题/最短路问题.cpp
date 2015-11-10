#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1004;
const int INF = 0x70ffffff;
int n, m;
int mat[MAXN][MAXN];
int d[MAXN], dp[MAXN][MAXN];
bool vis[MAXN];

void Dijkstra( int );

int main( int agrc, char *agrv[] )
{
    freopen( "test.in", "r", stdin );
    int T;
    scanf("%d", &T );
    while ( T-- ){
        int arrAy[4];
        arrAy[0] = 0;
        scanf("%d%d", &n, &m );
        n++;
        for ( int i = 1; i < 4; i++ ){
            scanf("%d", arrAy + i );
        }
        for ( int i = 0; i < n; i++ ){
            for ( int j = i + 1; j < n; j++ ){
                mat[i][j] = mat[j][i] = INF;
            }
        }
        int u, v, w;
        for ( int i = 0; i < m; i++ ){
            scanf("%d%d%d", &u, &v, &w );
            mat[u][v] = mat[v][u] = w;
        }
        for ( int i = 0; i < n; i++ ){
            Dijkstra( arrAy[i] );
            memcpy( dp[i], d, sizeof(d) );
        }
        int b[6];
        b[0] = dp[0][1] + dp[1][2] + dp[2][3];
        b[1] = dp[0][2] + dp[2][1] + dp[1][3];
        b[2] = dp[0][3] + dp[3][2] + dp[2][1];
        b[3] = dp[0][1] + dp[1][3] + dp[3][2];
        b[4] = dp[0][2] + dp[2][3] + dp[3][1];
        b[5] = dp[0][3] + dp[3][1] + dp[1][2];
        int ans(INF);
        for ( int i = 0; i < 6; i++ )   if ( ans > b[i] )   ans = b[i];
        printf("%d\n", ans );
    }

    return 0;
}
void Dijkstra( int x )
{
    memset( vis, false, sizeof( vis ) );
    for ( int i = 0; i < n; i++ )   d[i] = INF;
    d[x] = 0;
    for ( int i = 0;  i < n; i++ ){
        int Min(INF), z(0);
        for ( int y = 0; y < n; y++ ){
            if ( !vis[y] && d[y] <= Min )   Min = d[z=y];
        }
        vis[z] = true;
        for ( int y = 0; y < n; y++ )   d[y] = min( d[y], d[z] + mat[z][y] );
    }
}
