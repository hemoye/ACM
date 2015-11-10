#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 400;
const int INF = 0x3fffffff;

int m, n;
int dist[MAXN];
int arrAy[MAXN][MAXN];
bool vis[MAXN];

void Dijkstra( int );

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    while ( ~scanf("%d%d", &n, &m ) ){
        for ( int i = 1; i <= n; i++ ){
            for ( int j = 1; j <= n; j++ )  arrAy[i][j] = INF;
        }
        int u, v, weight;
        for ( int i = 0; i < m; i++ ){
            scanf("%d%d%d", &u, &v, &weight );
            arrAy[u][v] = arrAy[v][u] = weight;
        }
        Dijkstra( 1 );
        printf("%d\n", dist[n] );
    }

    return 0;
}
void Dijkstra( int cur )
{
    for ( int i = 1; i <= n; i++ ){
        dist[i] = arrAy[cur][i];
        vis[i] = false;
    }
    dist[cur] = 0;
    vis[cur] = true;
    for ( int i = 2; i <= n; i++ ){
        int mmin = INF;
        int u = cur;
        for ( int j = 1; j <= n; j++ ){
            if ( !vis[j] && dist[j] < mmin ){
                mmin = dist[j];
                u = j;
            }
        }
        vis[u] = true;
        for ( int j = 1; j <= n; j++ ){
            if ( !vis[j] && arrAy[u][j] < INF ) dist[j] = min( dist[j], dist[u] + arrAy[u][j] );
        }
    }

    return ;
}
