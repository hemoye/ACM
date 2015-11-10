#include <cstdio>
#include <cmath>
#include <algorithm>
#define  MAXN 10004
using namespace std;

const double PI = acos( -1.0 );
int N, F;
double arrAy[MAXN];

bool Judge( double );

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
    freopen( "test1.out", "w", stdout );
#endif
    int T;
    scanf("%d", &T );
    while ( T-- ){
        scanf("%d%d", &N, &F );
        double maxa = -1;
        for ( int i = 0; i < N; i++ ){
            int r;
            scanf("%d", &r );
            arrAy[i] = PI * r * r;
            maxa = max( maxa, arrAy[i] );
        }
        double L = 0, R = maxa;
        while ( R - L > 1e-5 ){
            double M = ( L + R ) / 2;
            if ( Judge( M ) )   L = M;
            else    R = M;
        }
        printf("%.3lf\n", L );
    }

    return 0;
}
bool Judge( double area )
{
    int sum = 0;
    for ( int i = 0; i < N; i++ ){
        sum += floor( arrAy[i] / area );
    }
    return sum >= F + 1;
}
