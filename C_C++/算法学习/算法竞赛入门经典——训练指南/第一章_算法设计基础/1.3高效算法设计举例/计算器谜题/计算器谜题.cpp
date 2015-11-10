#include <cstdio>
#include <algorithm>
#define  MAXN 40
using namespace std;

int Next( int , int );

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
    freopen( "test1.out", "w", stdout );
#endif
    int T;
    scanf("%d", &T );
    while ( T-- ){
        int n, k;
        scanf("%d%d", &n, &k );
        int ans = k;
        int k1 = k, k2 = k;
        do {
            k1 = Next( n, k1 );
            k2 = Next( n, k2 );
            if ( k2 > ans ) ans = k2;
            k2 = Next( n, k2 );
            if ( k2 > ans ) ans = k2;
        } while ( k1 != k2 );
        printf("%d\n", ans );
    }

    return 0;
}
int Next( int n, int k )
{
    int arrAy[MAXN];
    if ( !k )   return 0;
    long long k2 = ( long long )k * k;
    int L = 0;
    while ( k2 ){
        arrAy[L++] = k2 % 10;
        k2 /= 10;
    }
    if ( n > L ){
        n = L;
    }
    int ans = 0;
    for ( int i = 0; i < n; i++ ){
        ans = ans * 10 + arrAy[--L];
    }
    return ans;
}
