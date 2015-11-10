#include <cstdio>
#define  MAXN 1004

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
#endif
    int n;
    int arrAy[MAXN], d[MAXN];

    scanf("%d", &n );
    for ( int i = 0; i < n; i++ ){
        scanf("%d", arrAy + i );
    }
    int ans(0);
    for ( int i = 0; i < n; i++ ){
        d[i] = 1;
        for ( int j = 0; j < i; j++ ){
            if ( arrAy[j] < arrAy[i] && d[j] < d[i] + 1 ){
                d[i] = d[j] + 1;
            }
        }
        if ( ans < d[i] )   ans = d[i];
    }
    printf("%d\n", ans );

    return 0;
}
