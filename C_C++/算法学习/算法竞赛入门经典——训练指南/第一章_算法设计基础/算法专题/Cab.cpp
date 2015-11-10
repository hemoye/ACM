#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1004;
const int INF = 0x700000ff;
int n, m;
int vis[MAXN], d[MAXN], dp[4][MAXN];
int map[MAXN][MAXN];

void Dijkstra( int );

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int T;
    scanf("%d", &T );
    while ( T-- ){
        int arrAy[4];
        arrAy[0] = 0;
        scanf("%d%d", &n, &m );
        n++;
        for ( int i = 1; i < 4; i++ )   scanf("%d", arrAy + i );
        for ( int i = 0; i < n; i++ ){
            for (  int j = 0; j < n; j++ ){
                map[i][j] = INF;
            }
        }
        for ( int i = 0; i < m; i++ ){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w );
            map[u][v] = map[v][u] = w;
        }
        int ans = INF;
        for ( int i = 0; i < 4; i++ ){
            Dijkstra( arrAy[i] );
            memcpy( dp[i], d, sizeof(d) );
        }
        int b[6];
        b[0] = dp[0][arrAy[1]]+dp[1][arrAy[2]]+dp[2][arrAy[3]];
        b[1] = dp[0][arrAy[1]]+dp[1][arrAy[3]]+dp[3][arrAy[2]];
        b[2] = dp[0][arrAy[2]]+dp[2][arrAy[1]]+dp[1][arrAy[3]];
        b[3] = dp[0][arrAy[2]]+dp[2][arrAy[3]]+dp[3][arrAy[1]];
        b[4] = dp[0][arrAy[3]]+dp[3][arrAy[1]]+dp[1][arrAy[2]];
        b[5] = dp[0][arrAy[3]]+dp[3][arrAy[2]]+dp[2][arrAy[1]];
        for ( int i = 0; i < 6; i++ )   ans = min( ans, b[i] );
        printf("%d\n", ans );
    }

    return 0;
}
void Dijkstra( int x )
{
    memset( vis, 0, sizeof( vis ) );
    for ( int i = 0; i < n; i++ )   d[i] = INF;
    d[x] = 0;
    for ( int y = 0; y < n; y++ ){
        int m(INF), z(0);
        for ( int y = 0; y < n; y++ ){
            if ( !vis[y] && d[y] <= m )     m = d[z=y];
        }
        vis[z] = 1;
        for ( int y = 0; y < n; y++ ) d[y] = min( d[y], d[z] + map[z][y] );
    }
}
