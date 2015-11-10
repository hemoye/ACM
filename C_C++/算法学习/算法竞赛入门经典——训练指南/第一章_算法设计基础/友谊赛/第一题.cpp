#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1004;
const int INF = 20130602;
int arrAy[MAXN];

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n;

    memset( arrAy, 0, sizeof( arrAy ) );
    arrAy[1] = 1;
    for ( int i = 2; i <= 1001; i++ ){
        for ( int k = 1; k <= 5; k++ ){
            if ( i - k > 0 )    arrAy[i] += arrAy[i-k];
        }
        arrAy[i] %= INF;
    }

    while ( ~scanf("%d", &n ) ){
        printf("%d\n", arrAy[n+1] );
    }

    return 0;
}
