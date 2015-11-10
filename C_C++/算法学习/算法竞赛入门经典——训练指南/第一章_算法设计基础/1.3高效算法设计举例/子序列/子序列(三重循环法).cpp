#include <cstdio>
#include <algorithm>
#define  MAXN 100004
using namespace std;

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
#endif
    int n, S;
    int arrAy[MAXN];
    while ( ~scanf("%d%d", &n, &S) ){
        for ( int i = 0; i < n; i++ ){
            scanf("%d", arrAy + i );
        }
        int ans = n + 1;
        for ( int i = 0; i < n; i++ ){
            for ( int j = i; j < n; j++ ){
                int sum(0);
                for ( int k = i; k <= j; k++ ){
                    sum += arrAy[k];
                }
                if ( sum >= S ){
                    ans = min( ans, j - i + 1 );
                }
            }
        }
        printf("%d\n", ans );
    }

    return 0;
}
