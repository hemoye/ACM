#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 5004;
const int INF = 20130601;
int arrAy[MAXN];

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n;
    while ( ~scanf("%d", &n ) ){
        int ans(0);
        for ( int i = 0; i < n; i++ )   scanf("%d", arrAy + i );
        for ( int i = 0; i < n; i++ ){
            for ( int j = 0; j < n; j++ ){
                for ( int k = i; k <= j; k++ )
                    ans = ( ans + arrAy[k] ) % INF;
            }
        }
        printf("%d\n", ans );
    }

    return 0;
}
