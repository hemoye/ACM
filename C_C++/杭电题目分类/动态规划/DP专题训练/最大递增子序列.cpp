#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1004;

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n;
    int arrAy[MAXN], dp[MAXN];
    while ( ~scanf("%d", &n ) && n ){
        for ( int i = 0; i < n; i++ )   scanf("%d", arrAy + i );
        memset( dp, 0, sizeof(dp) );
        dp[0] = arrAy[0];
        int xmax;
        for ( int i = 1; i < n; i++ ){
            xmax = 0;
            for ( int j = 0; j < i; j++ ){
                if ( arrAy[j] < arrAy[i] )  xmax = max( xmax, dp[j] );
            }
            if ( xmax )     dp[i] = xmax + arrAy[i];
            else    dp[i] = arrAy[i];
        }
        xmax = 0;
        for ( int i = 0; i < n; i++ )   xmax = max( xmax, dp[i] );
        printf("%d\n", xmax );
    }

    return 0;
}
