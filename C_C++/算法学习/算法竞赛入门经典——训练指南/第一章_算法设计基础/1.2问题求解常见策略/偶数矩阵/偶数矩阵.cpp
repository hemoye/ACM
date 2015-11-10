#include <cstdio>
#include <cstring>
#include <algorithm>
#define  MAXN 20
#define  INF 1000000000

using namespace std;

int arrAy[MAXN][MAXN], brr[MAXN][MAXN];
int n;

int Check( int );

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
    freopen( "test1.out", "w", stdout );
#endif
    int T;
    scanf("%d", &T );
    for ( int k = 1; k <= T; k++ ){
        scanf("%d", &n );
        for ( int i = 0; i < n; i++ ){
            for ( int j = 0; j < n; j++ ){
                scanf("%d", &arrAy[i][j] );
            }
        }
        int ans( INF );
        int t = 1 << n;
        for ( int i = 0; i < t; i++ ){
            ans = min( ans, Check( i ) );
        }
        if ( ans == INF ){
            ans = -1;
        }
        printf("Case #%d: %d\n", k, ans );
    }

    return 0;
}
int Check( int s )
{
    memset( brr, 0, sizeof( brr ) );
    for ( int i = 0; i < n; i++ ){
        if ( s & ( 1 << i ) ){
            brr[0][i] = 1;
        }
        else if ( 1 == arrAy[0][i] ){
            return INF;
        }
    }
    for ( int i = 1; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            int sum(0);
            if ( i > 1 ){
                sum += brr[i-2][j];
            }
            if ( j > 0 ){
                sum += brr[i-1][j-1];
            }
            if ( j < n - 1 ){
                sum += brr[i-1][j+1];
            }
            brr[i][j] = sum % 2;
            if ( arrAy[i][j] && 0 == brr[i][j] ){
                return INF;
            }
        }
    }
    int cnt(0);
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            if ( arrAy[i][j] != brr[i][j] ){
                cnt++;
            }
        }
    }
    return cnt;

}
