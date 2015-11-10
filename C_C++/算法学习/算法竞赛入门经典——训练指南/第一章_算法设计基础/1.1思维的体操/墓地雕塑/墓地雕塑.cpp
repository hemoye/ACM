#include <cmath>
#include <cstdio>
#define  MAXN 1004

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
    freopen( "test1.out", "w", stdout );
#endif
    int n, m;
    while ( scanf("%d%d", &n, &m ) != EOF ){
        double ans = 0.0;
        for ( int i = 1; i < n; i++ ){
            double pos = ( double ) i / n * ( n + m );
            ans += fabs( pos - floor( pos + 0.5 ) ) / ( n + m );
        }
        printf("%.4lf\n", ans * 10000 );
    }

    return 0;
}
