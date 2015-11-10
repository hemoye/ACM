#include <cstdio>
#include <algorithm>
#define  MAXN 100004
using namespace std;

int n, arrAy[MAXN];
int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
    freopen( "test1.out", "w", stdout );
#endif
    int T;
    scanf("%d", &T );
    while ( T-- ){
        scanf("%d", &n );
        for ( int i = 0; i < n; i++ ){
            scanf("%d", arrAy + i );
        }
        int ans = arrAy[0] - arrAy[1];
        for ( int i = 0; i < n; i++ ){
            for ( int j = i + 1; j < n; j++ ){
                ans = max( ans, arrAy[i] - arrAy[j] );
            }
        }
        printf("%d\n", ans );
    }

    return 0;
}
