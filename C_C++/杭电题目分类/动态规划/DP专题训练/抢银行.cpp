#include <cstdio>
#include <algorithm>
#define  MAXN 10004
using namespace std;

struct Bank {
    int money;
    double p;
} bank[MAXN];

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int T;
    scanf("%d", &T );
    while ( T-- ){
        int n, sum(0);
        double p;
        scanf("%lf%d", &p, &n );
        p = 1 - p;
        for ( int i = 0; i < n; i++ ){
            scanf("%d%lf", &bank[i].money, &bank[i].p );
            bank[i].p = 1 - bank[i].p;
            sum += bank[i].money;
        }
        double dp[MAXN] = {1.0};
        for ( int i = 0; i < n; i++ ){
            for ( int j = sum; j >= bank[i].money; j-- ){
                dp[j] = max( dp[j], dp[j-bank[i].money] * bank[i].p );
            }
        }
        for ( int i = sum; i >= 0; i-- ){
            if ( dp[i] - p > 0.00000001 ){
                printf("%d\n", i );
                break;
            }
        }
    }

    return 0;
}
