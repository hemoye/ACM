#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 100004;
int arrAy[MAXN];
int fuzhu[MAXN];

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n, m;
    while ( ~scanf("%d%d", &n, &m ) ){
        for ( int i = 1; i <= n; i++ ){
            scanf("%d", arrAy + i );
        }
        memset( fuzhu, 0, sizeof( fuzhu ) );
        int L, R;
        for ( int i = 0; i < m; i++ ){
            int ans(0);
            scanf("%d%d", &L, &R );
            for ( int j = L; j <= R; j++ ){
                int x(0);
                for ( int k = 1; k < n; k++ ){
                    if ( j == arrAy[k] )    x++;
                }
                if ( x == j )   ans++;
            }
            printf("%d\n", ans );
        }
    }

    return 0;
}
