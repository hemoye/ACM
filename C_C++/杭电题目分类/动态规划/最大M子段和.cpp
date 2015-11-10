#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000004;
const int INF = 0x4fffffff;

int m, n;
int arrAy[MAXN];
int dp[MAXN], Aid[MAXN];

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    while ( ~scanf("%d%d", &m, &n ) ){
        for ( int i = 1; i <= n; i++ ){
            scanf("%d", arrAy + i );
            dp[i] = Aid[i] = -INF;
        }
        for ( int i = 1; i <= n; i++ ){
            int t = min( m, i );
            for ( int j = 1; j <= t; j++ ){
                dp[j] = max( dp[j], Aid[j-1] ) + arrAy[i];
                Aid[j-1] = max( dp[j-1], Aid[j-1] );
            }
            Aid[t] = max( dp[t], Aid[t] );
        }
        printf("%d\n", Aid[m] );
    }

    return 0;
}
