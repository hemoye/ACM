#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1004;

int m, n;
int high[MAXN][MAXN], mat[MAXN][MAXN];
int left[MAXN], right[MAXN];

int Area( void );

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int T;
    char ch;
    scanf("%d", &T );
    while ( T-- ){
        scanf("%d%d", &n, &m );
        for ( int i = 0; i < n; i++ ){
            for ( int j = 0; j < m; j++ ){
                ch = getchar();
                while ( ch != 'F' && ch != 'R' )    ch = getchar();
                mat[i][j] = ch == 'R' ? 0 : 1;
            }
        }
        printf("%d\n", 3 * Area() );
    }

    return 0;
}
int Area( void )
{
    int ans(0);
    for ( int i = 0; i < m; i++ )   high[0][i] = mat[0][i];
    for ( int i = 1; i < n; i++ ){
        for ( int j = 0; j < m; j++ ){
            if ( mat[i][j] )    high[i][j] = high[i-1][j] + 1;
            else    high[i][j] = 0;
        }
    }
    for ( int j = 0; j < n; j++ ){
        memset( left, 0, m );
        memset( right, 0, m );
        for ( int i = 0; i < m; i++ ){
            left[i] = i;
            while ( high[j][i] <= high[j][left[i]-1] && left[i] > 0 )   left[i] = left[left[i]-1];
        }
        for ( int i = m - 1; i >= 0; i-- ){
            right[i] = i;
            while ( high[j][i] <= high[j][right[i]+1] && right[i] < m - 1 )  right[i] = right[right[i]+1];
        }
        for ( int i = 0; i < m; i++ ){
            int m = high[j][i] * ( right[i] - left[i] + 1 );
            ans = max( ans, m );
        }
    }
    return ans;
}
