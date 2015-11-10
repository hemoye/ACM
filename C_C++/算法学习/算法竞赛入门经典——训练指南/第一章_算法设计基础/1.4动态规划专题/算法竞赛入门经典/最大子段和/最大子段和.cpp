#include <cstdio>
#define  MAXN 1004

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "in.in", "r", stdin );
#endif
    int n;
    int arrAy[MAXN];

    while ( ~scanf("%d", &n ) ){
        for ( int i = 0; i < n; i++ ){
            scanf("%d", arrAy + i );
        }
        int x(0), sum(0);
        for ( int i = 0; i < n; i++ ){
            x += arrAy[i];
            if ( x < 0 ){
                x = 0;
            }
            if ( sum < x ){
                sum = x;
            }
        }
        printf("%d\n", sum );
    }

    return 0;
}
