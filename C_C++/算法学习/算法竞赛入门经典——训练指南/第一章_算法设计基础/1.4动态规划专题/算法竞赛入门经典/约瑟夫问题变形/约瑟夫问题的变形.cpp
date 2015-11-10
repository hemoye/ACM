#include <cstdio>
#define  MAXN 10002

int arrAy[MAXN];

int main( int agrc, char *agrv[] )
{
    int n, k, m;
    while ( ~scanf("%d%d%d", &n, &k, &m ) ){
        if ( n == m && m == k && k == 0 )   break;
        arrAy[1] = 0;
        for ( int i = 2; i <= n; i++ )   arrAy[i] = ( arrAy[i-1] + k ) % i;
        int ans = ( m - k + 1 + arrAy[n] ) % n;
        if ( ans <= 0 ) ans += n;
        printf("%d\n", ans );
    }
}
