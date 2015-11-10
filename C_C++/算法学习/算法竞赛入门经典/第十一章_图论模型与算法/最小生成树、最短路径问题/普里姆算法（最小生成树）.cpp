#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 104;
const int INF = 0x7fffffff;

int m, n;
int arrAy[MAXN][MAXN];

int Prim( void );

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    while ( ~scanf("%d%d", &n, &m ) ){
        for ( int i = 1; i <= n; i++ ){
            for ( int j = 1; j <= n; j++ )  arrAy[i][j] = INF;
        }
        int u, v, w;
        for ( int i = 0; i < m; i++ ){
            scanf("%d%d%d", &u, &v, &w );
            arrAy[u][v] = arrAy[v][u] = w;
        }
        printf("%d\n", Prim() );
    }

    return 0;
}
int Prim( void )
{
    int ans(0);
    int count(0);
    bool vis[n+10];
    for ( int i = 2; i <= n; i++ )  vis[i] = false;
    vis[1] = true;
    while ( count++ < n ){
        int mmin = INF;
        int e1(-1), e2(-1);
        for ( int i = 1; i <= n; i++ ){
            if ( vis[i] ){
                for ( int j = 1; j <= n; j++ ){
                    if ( !vis[j] && arrAy[i][j] < mmin ){
                        e1 = i;
                        e2 = j;
                        mmin = arrAy[i][j];
                    }
                }
            }
        }
        printf("%d %d %d\n", e1, e2, arrAy[e1][e2] );
        vis[e2] = true;
        ans += arrAy[e1][e2];
    }
    return ans;
}
