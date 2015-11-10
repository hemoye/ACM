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
    int T;
    int n, value;
    scanf("%d", &T );
    while ( T-- ){
        int bone[MAXN], money[MAXN];
        scanf("%d%d", &n, &value );
        for ( int i = 0; i < n; i++ )   scanf("%d", money + i );
        for ( int i = 0; i < n; i++ )   scanf("%d", bone + i );
        int dp[MAXN*10];
        memset( dp, 0, sizeof(dp) );
        for ( int i = 0; i < n; i++ ){
            for ( int j = value; j >= bone[i]; j-- ){
                dp[j] = max( dp[j], dp[j-bone[i]] + money[i] );
            }
        }
        printf("%d\n", dp[value] );
    }

    return 0;
}
