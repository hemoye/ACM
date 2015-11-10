#include <cstdio>
#include <algorithm>
#define  MAXN 1000004

using namespace std;

long long arrAy[MAXN], result[MAXN];
long long total, average;

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n;

    while ( scanf("%d", &n ) != EOF ){
        total = 0;
        for ( int i = 0; i < n; i++ ){
            scanf("%d", arrAy + i );
            total += arrAy[i];
        }
        average = total / n;
        result[0] = 0;
        for ( int i = 1; i < n; i++ ){
            result[i] = result[i-1] + arrAy[i] - average;
        }
        sort( result, result + n );
        long long ans(0);
        long long x = result[n/2];
        for ( int i = 0; i < n ; i++ ){
            ans += abs( x - result[i] );
        }
        printf("%d\n", ans );
    }

    return 0;
}
