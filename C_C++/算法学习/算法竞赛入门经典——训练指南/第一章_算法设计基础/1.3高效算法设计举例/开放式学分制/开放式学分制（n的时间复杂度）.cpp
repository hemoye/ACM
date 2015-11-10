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
        int MaxAi( arrAy[0] );
        for ( int i = 1; i < n; i++ ){
            ans = max( ans, MaxAi - arrAy[i] );
            MaxAi = max( arrAy[i], MaxAi );
        }
        printf("%d\n", ans );
    }

    return 0;
}
