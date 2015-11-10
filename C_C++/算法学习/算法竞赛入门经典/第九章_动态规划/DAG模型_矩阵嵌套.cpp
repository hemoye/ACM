#include <iostream>
#include <cstring>
#define  MAXN 40
#define  Swap( a, b, t ) t = a, a = b, b = t

int G[MAXN][MAXN];
int vis[MAXN];

int dp( int , int );

int main( void )
{
    using namespace std;

    int t, num, temp;
    int a[MAXN], b[MAXN];

    cin >> t;
    while ( t-- ){
        memset( G, 0, sizeof( G ) );
        memset( vis, 0, sizeof( vis ) );
        cin >> num;
        for ( int i = 1; i <= num; i++ ){
            cin >> a[i] >> b[i];
            if ( a[i] > b[i] ){
                Swap( a[i], b[i], temp );
            }
        }
        for ( int i = 1; i <= num; i++ ){
            for ( int j = 1; j <= num; j++ ){
                if ( a[j] < a[i] && b[j] < b[i] ){
                    G[i][j] = 1;
                }
            }
        }
        int max( 0 );
        for ( int i = 1; i <= num; i++ ){
            temp = dp( i, num );
            if ( max < temp ){
                max = temp;
            }
        }
        cout << max << endl;
    }

    return 0;
}
int dp( int i, int n )
{
    int &ans = vis[i];
    if ( ans > 0 ) return ans;
    ans = 1;
    for ( int j = 1; j <= n; j++ ){
        if ( G[i][j] ){
            int temp = dp( i, n ) + 1;
            if ( ans < temp ){
                ans = temp;
            }
        }
    }
    return ans;
}
