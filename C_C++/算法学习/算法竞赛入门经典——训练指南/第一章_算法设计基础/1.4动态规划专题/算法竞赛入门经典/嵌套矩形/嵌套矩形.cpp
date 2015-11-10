#include <cstdio>
#include <cstring>
#include <algorithm>
#define  Swap( a, b, t ) t = a, a = b, b = t
#define  MAXN 400
using namespace std;

int G[MAXN][MAXN];
int vis[MAXN];
int dp( int , int );

int main( int agrc, char *agrv[] )
{
    int n, t;
    int a[MAXN], b[MAXN];

    while ( ~scanf("%d", &n ) ){
        memset( G, 0, sizeof( G ) );
        memset( vis, -1, sizeof( vis ) );
        for ( int i = 0; i < n; i++ ){
            scanf("%d%d", &a[i], &b[i] );
            if ( a[i] > b[i] ){
                Swap( a[i], b[i], t );
            }
        }
        for ( int i = 0; i < n; i++ ){
            for ( int j = 0; j < n; j++ ){
                if ( a[j] < a[i] && b[j] < b[i] ){
                    G[i][j] = 1;
                }
            }
        }
        int ans(0);
        for ( int i = 0; i < n; i++ ){
            int temp = dp( i, n );
            ans = max( ans, temp );
        }
        printf("%d\n", ans );
    }

    return 0;
}
int dp( int i, int n )
{
    int &ans = vis[i];
    if ( ans >= 0 ){
        return ans;
    }
    ans = 1;
    for ( int j = 0; j < n; j++ ){
        if ( G[i][j] ){
            int temp = dp( j, n ) + 1;
            ans = max( ans, temp );
        }
    }
    return ans;
}
