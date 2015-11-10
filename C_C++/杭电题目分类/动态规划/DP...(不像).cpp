#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1000004;

int arrAy[MAXN];

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n;
    while ( ~scanf("%d", &n ) ){
        for ( int i = 1; i <= n; i++ )  scanf("%d", arrAy + i );
        if ( 1 == n ){
            printf("%d\n", arrAy[n] );
            continue;
        }
        for ( int i = 1; i <= n; i++ ){
            int ans(1);
            for ( int j = i + 1; j <= n; j++ ){
                if ( arrAy[j] == arrAy[i] ) ans++;
            }
            if ( ans >= ( n + 1 ) / 2 ){
                printf("%d\n", arrAy[i] );
                break;
            }
        }
    }

    return 0;
}
