#include <cstdio>
#include <cstring>
#include <algorithm>
#define  MAXN 104
using namespace std;

int S[MAXN], arrAy[MAXN];
int d[MAXN][MAXN], vis[MAXN][MAXN];

int dp( int i, int j )
{
    if ( vis[i][j] ){
        return d[i][j];
    }
    vis[i][j] = 1;
    int m(0);
    for ( int k = i + 1; k <= j; k++ )  m = min( m, dp( k, j ) );
    for ( int k = i; k < j; k++ )   m = min( m, dp( i, k ) );
    d[i][j] = S[j] - S[i-1] - m;
    return d[i][j];
}
int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "in.in", "r", stdin );
#endif
    int n;
    while ( ~scanf("%d", &n ) && n ){
        S[0] = 0;
        for ( int i = 1; i <= n; i++ ){
            scanf("%d", arrAy + i );
            S[i] = S[i-1] + arrAy[i];
        }
        memset( vis, 0, sizeof( vis ) );
        printf("%d\n", 2 * dp( 1, n ) - S[n] );
    }

    return 0;
}
