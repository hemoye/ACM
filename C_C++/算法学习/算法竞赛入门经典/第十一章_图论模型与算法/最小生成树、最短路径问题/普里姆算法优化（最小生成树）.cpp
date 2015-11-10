#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 40;
const int INF = 0x5fffffff;

int n, m;
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
        for ( int i = 1; i <= m; i++ ){
            scanf("%d%d%d", &u, &v, &w );
            arrAy[u][v] = arrAy[v][u] = w;
        }
        printf("%d\n", Prim() );
    }

    return 0;
}
int Prim( void )
{
    /**记当前生成树的结点集合为S,未使用的结点集合为V**/
    int ans(0);
    bool vis[MAXN];                         /**记录顶点是否在集合S中**/
    int nearest[MAXN];                      /**记录V中每个点到S中邻接点的最短边**/
    int adjecent[MAXN];                     /**记录与V中每个点最邻接近的点**/
    /**初始化集合S**/
    for ( int i = 2; i <= n; i++ )  vis[i] = false;
    vis[1] = true;
    for ( int i = 1; i <= n; i++ ){
        nearest[i] = arrAy[1][i];
        adjecent[i] = 1;
    }
    int count(n);
    while ( --count ){
        int e(1), mmin(INF);
        for ( int i = 1; i <= n; i++ ){
            if ( !vis[i] && nearest[i] < mmin ){
                mmin = nearest[i];
                e = i;
            }
        }
        ans += arrAy[e][adjecent[e]];
        vis[e] = true;
        for ( int i = 1; i <= n; i++ ){
            if ( !vis[i] && arrAy[i][e] < nearest[i] ){
                nearest[i] = arrAy[i][e];
                adjecent[i] = e;
            }
        }
    }
    return ans;
}
