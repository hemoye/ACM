#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 400;

int n, m;
int u[MAXN], v[MAXN], weight[MAXN];
int p[MAXN], r[MAXN];

bool cmp( const int x, const int y ){ return weight[x] < weight[y]; };
int  Find( int x ){ p[x] == x ? x : Find( p[x] ); };

int Kruskal( void )
{
    int ans(0);
    for ( int i = 1; i <= n; i++ )  p[i] = i;   /**初始化并查集**/
    for ( int i = 1; i <= m; i++ )  r[i] = i;   /**初始化边序号**/
    sort( r, r + m, cmp );                      /**按照权值大小给边升序排序**/
    for ( int i = 1; i <= m; i++ ){
        int e = r[i];
        int x = Find( u[e] );
        int y = Find( v[e] );
        if ( x - y ){
            ans += weight[e];
            p[x] = y;
        }
    }
    return ans;
}

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    while ( ~scanf("%d%d", &n, &m ) ){
        for ( int i = 1; i <= m; i++ )  scanf("%d%d%d", u + i, v + i, weight + i );
        printf("%d\n", Kruskal() );
    }

    return 0;
}
