#include <cstdio>
#include <cstring>
#include <algorithm>
#define  MAXN 251 * 251
#define  INF 1000000000
using namespace std;

int S[MAXN], g[MAXN], d[MAXN];
int num[MAXN];

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "in.in", "r", stdin );
//    freopen( "test1.out", "w", stdout );
#endif
    int T;
    scanf("%d", &T );
    for ( int kase = 1; kase <= T; kase++ ){
        int N, q, p, x;
        scanf("%d%d%d", &N, &p, &q );
        memset( num, 0, sizeof( num ) );
        for ( int i = 1; i <= p + 1; i++ ){
            scanf("%d", &x );
            num[x] = i;
        }
        int n = 0;
        for ( int i = 0; i < q + 1; i++ ){
            scanf("%d", &x );
            if ( num[x] ){
                S[n++] = num[x];
            }
        }
        for ( int i = 1; i <= n; i++ )  g[i] = INF;
        int ans = 0;
        for ( int i = 0; i < n; i++ ){
            int k = lower_bound( g + 1, g + n + 1, S[i] ) - g;
            d[i] = k;
            g[k] = S[i];
            ans = max( ans, d[i] );
        }
        printf("Case %d: %d\n", kase, ans );
    }

    return 0;
}
