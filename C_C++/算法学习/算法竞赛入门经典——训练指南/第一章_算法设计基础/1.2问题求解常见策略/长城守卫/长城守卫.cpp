#include <cstdio>
#include <algorithm>
#define  MAXN 100004
using namespace std;

int n, r[MAXN], left[MAXN], right[MAXN];

bool test( int );

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
    freopen( "test.out", "w", stdout );
#endif
    while ( ~scanf("%d", &n ) && n ){
        for ( int i = 1; i <= n; i++ ){
            scanf("%d", &r[i] );
        }
        r[n+1] = r[1];

        int L = 0, R = 0;
        for ( int i = 1; i <= n; i++ ){
            L = max( L, r[i] + r[i+1] );
        }
        if ( n % 2 ){
            for ( int i = 1; i <= n; i++ ){
                R = max( R, r[i] * 3 );
            }
            while ( L < R ){
                int M = L + ( R - L ) / 2;
                if ( test( M ) ){
                    R = M;
                }
                else {
                    L = M + 1;
                }
            }
        }
        printf("%d\n", L );
    }

    return 0;
}
bool test( int p )
{
    int x = r[1], y = p - r[1];
    int id(0);
    left[0] = x;
    right[0] = 0;
    for ( int i = 2; i <= n; i++ ){
        id = !id;
        if ( i & 1 ){
            right[id] = min( y - right[!id], r[i] );
            left[id] = r[i] - right[id];
        }
        else {
            left[id] = min( x - left[!id], r[i] );
            right[id] = r[i] - left[id];
        }
    }
    return 0 == left[id];
}
