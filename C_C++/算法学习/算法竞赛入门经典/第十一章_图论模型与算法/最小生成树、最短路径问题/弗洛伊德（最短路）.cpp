#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 400;
const int INF = 0x3fffffff;

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n, m;
    int arrAy[MAXN][MAXN];

    while ( ~scanf("%d%d", &n, &m ) ){
        for ( int i = 1; i <= n; i++ ){
            for ( int j = 1; j <= n; j++ )   arrAy[i][j] = INF;
        }
        int u, v, weight;
        for ( int i = 0; i < m; i++ ){
            scanf("%d%d%d", &u, &v, &weight );
            arrAy[u][v] = arrAy[v][u] = weight;
        }
        for ( int k = 1; k <= n; k++ ){
            for ( int i = 1; i <= n; i++ ){
                for ( int j = 1; j <= n; j++ ){
                    arrAy[i][j] = min( arrAy[i][j], arrAy[i][k] + arrAy[k][j] );
                }
            }
        }
        printf("%d\n", arrAy[1][n] );
        for ( int i = 1; i <= n; i++ ){
            for ( int j = 1; j <= n; j++ )   printf("%d ", arrAy[i][j] );
            puts("");
        }
    }

    return 0;
}
