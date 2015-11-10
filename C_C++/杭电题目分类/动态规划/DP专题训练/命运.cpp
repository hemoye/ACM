#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1004;

int arrAy[40][MAXN];

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int T;
    int m, n;
    scanf("%d", &T );
    while ( T-- ){
        scanf("%d%d", &n, &m );
        for ( int i = 1; i <= n; i++ ){
            for ( int j = 1; j <= m; j++ )  scanf("%d", &arrAy[i][j] );
        }
        for ( int i = 1; i <= n; i++ ){
            for ( int j = 1; j <= m; j++ ){
                if ( i > 1 || j > 1 ){
                    int ans(-9999999);
                    for ( int k = 2; k <= j; k++ ){
                        if ( 0 == j % k )   ans = max( ans, arrAy[i][j/k] );
                    }
                    if ( i > 1 )    ans = max( ans, arrAy[i-1][j] );
                    if ( j > 1 )    ans = max( ans, arrAy[i][j-1] );
                    arrAy[i][j] += ans;
                }
            }
        }
        printf("%d\n", arrAy[n][m] );
    }

    return 0;
}
