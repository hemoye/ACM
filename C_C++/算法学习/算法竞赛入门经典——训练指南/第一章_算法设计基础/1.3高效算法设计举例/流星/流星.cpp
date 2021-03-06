#include <cstdio>
#include <algorithm>
#define  MAXN 100004
using namespace std;

struct Event {
    double x;
    int type;
    bool operator < ( const Event &a ) const {
        return  x < a.x || ( x == a.x && type > a.type ); /**�ȴ����Ҷ˵�**/
    }
} events[2*MAXN];
void Update( int , int , int , double & , double & );

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
    freopen( "test1.out", "w", stdout );
#endif
    int T;
    scanf("%d", &T );
    while ( T-- ){
        int w, h, n;
        int e(0);
        scanf("%d%d%d", &w, &h, &n );
        for ( int i = 0; i < n; i++ ){
            int x, y, a, b;
            scanf("%d%d%d%d", &x, &y, &a, &b );
            double L(0), R(1e9);
            Update( x, a, w, L, R );
            Update( y, b, h, L, R );
            if ( L < R ){
                events[e++] = ( Event ){ L, 1 };
                events[e++] = ( Event ){ R, 0 };
            }
        }
        sort( events, events + e );
        int cnt(0), ans(0);
        for ( int i = 0; i < n; i++ ){
            if ( events[i].type ){
                ans = max( ans, ++cnt );
            }
            else {
                cnt--;
            }
        }
        printf("%d\n", ans );
    }

    return 0;
}
void Update( int x, int a, int w, double & L, double & R )
{
    if ( 0 == a ){
        if ( x <= 0 || x >= w ) R = L - 1;
    }
    else if ( a > 0){
        L = max( L, -( double ) x / a );
        R = min( R, ( double )( w - x ) / a );
    }
    else {
        L = max( L, ( double )( w - x ) / a );
        R = min( R, -( double ) x / a );
    }
    return ;
}
