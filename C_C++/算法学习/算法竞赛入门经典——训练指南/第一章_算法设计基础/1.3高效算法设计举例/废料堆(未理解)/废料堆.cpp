#include <cstdio>
#include <cstring>
#include <algorithm>
#define  MAXN 40
#define  FOR( i, s, t ) for ( int i = (s); i <= (t); i++ )
using namespace std;

void expand( int i, int &b, int &b1, int b2 )
{
    b = 1 & i;
    i >>=  1;
    b1 = i & 1;
    i >>= 1;
    b2 = i & 1;
    return ;
}
int sign( int b, int b1, int b2 )
{
    return ( b + b1 + b2 ) % 2 == 1 ? 1 : -1;
}
const long long INF = 1LL << 60;
long long S[MAXN][MAXN][MAXN];

long long sum( int x1, int x2, int y1, int y2, int z1, int z2 )
{
    int dx = x2 - x1 + 1, dy = y2 - y1 + 1, dz = z2 - z1 + 1;
    long long s(0);

    for ( int i = 0; i < 8; i++ ){
        int b, b1, b2;
        expand( i, b, b1, b2 );
        s -= S[x2-b*dx][y2-b1*dy][z2-b2*dz] * sign( b, b1, b2 );
    }
    return s;
}
int main( int agrc, char *agrv[] )
{
    int T;
    scanf("%d", &T );
    while ( T-- ){
        int a, b, c, b0, b1, b2;
        scanf("%d%d%d", &a, &b, &c );
        memset( S, 0, sizeof( S ) );
        FOR( x, 1, a )  FOR( y, 1, b ) FOR( z, 1, c ) scanf("%lld", &S[x][y][z] );
        FOR( x, 1, a )  FOR( y, 1, b ) FOR( z, 1, c ) FOR( i, 1, 7 ){
            expand( i, b0, b1, b2 );
            S[x][y][z] += S[x-b0][y-b1][z-b2] * sign( b0, b1, b2 );
        }
        long long ans = -INF;
        FOR( x1, 1, a ) FOR( x2, x1, a ) FOR( y1, 1, b ) FOR( y2, y1, b ){
            long long M(0);
            FOR ( z, 1, c ){
                long long s = sum( x1, x2, y1, y2, 1, z );
                ans = max( ans, s - M );
                M = min( M, s );
            }
        }
        printf("%lld\n", ans );
        if ( T ){
            puts("");
        }
    }
}
