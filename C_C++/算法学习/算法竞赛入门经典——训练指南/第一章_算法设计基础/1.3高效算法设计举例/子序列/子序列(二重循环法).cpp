#include <cstdio>
#include <algorithm>
#define  MAXN 100004
using namespace std;

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
#endif
    int x, n, S;
    int arrAy[MAXN];
    while ( ~scanf("%d%d", &n, &S ) ){
        arrAy[0] = 0;
        for ( int i = 1; i <= n; i++ ){
            scanf("%d", &x );
            arrAy[i] = arrAy[i-1] + x;
        }
        int ans( n + 1 );
        for ( int i = 1; i <= n; i++ ){
            for ( int j = i; j <= n; j++ ){
                if ( arrAy[j] - arrAy[i-1] >= S ){
                    ans = min( ans, j - i + 1 );
                }
            }
        }
        printf("%d\n", ans );
    }

    return 0;
}
