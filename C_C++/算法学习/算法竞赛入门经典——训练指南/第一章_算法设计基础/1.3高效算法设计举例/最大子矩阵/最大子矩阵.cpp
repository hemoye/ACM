#include <cstdio>
#include <algorithm>
#define  MAXN 1004
using namespace std;

int mat[MAXN][MAXN], up[MAXN][MAXN], left[MAXN][MAXN], right[MAXN][MAXN];

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
    freopen( "test1.out", "w",stdout );
#endif
    int T;
    scanf("%d", &T );
    while ( T-- ){
        int m, n;
        scanf("%d%d", &m, &n );
        for ( int i = 0; i < m; i++ ){
            for ( int j = 0; j < n; j++ ){
                char ch = getchar();
                while ( ch != 'F' && ch != 'R' )    ch = getchar();
                mat[i][j] = ch == 'F' ? 0 : 1;
            }
        }
        int ans(0);
        for ( int i = 0; i < m; i++ ){
            int lo = -1, ro = n;
            for ( int j = 0; j < n; j++ ){
                if ( mat[i][j] ){
                    up[i][j] = left[i][j] = 0;
                    lo = j;
                }
                else {
                    up[i][j] = i == 0 ? 1 : up[i-1][j] + 1;
                    left[i][j] = i == 0 ? lo + 1 : max( left[i-1][j], lo + 1 );
                }
            }
            for ( int j = n - 1; j >= 0; j-- ){
                if ( mat[i][j] ){
                    right[i][j] = n;
                    ro = j;
                }
                else {
                    right[i][j] = i == 0 ? ro - 1 : min( right[i-1][j], ro - 1 );
                    ans = max( ans, up[i][j] * ( right[i][j] - left[i][j] + 1 ) );
                }
            }
        }
        printf("%d\n", ans * 3 );
    }

    return 0;
}
