#include <cstdio>
#include <algorithm>
#define  MAXN 400
using namespace std;

int n;
int arrAy[MAXN][MAXN];

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
    freopen( "test.out", "w", stdout );
#endif
    while ( ~scanf("%d", &n ) ){
        for ( int i = 0; i < n; i++ ){
            for ( int j = 0; j <= i; j++ ){
                scanf("%d", &arrAy[i][j] );
            }
        }
        for ( int i = n - 2; i >= 0; i-- ){
            for ( int j = 0; j <= i; j++ ){
                arrAy[i][j] += max( arrAy[i+1][j], arrAy[i+1][j+1] );
            }
        }
        printf("%d\n", arrAy[0][0] );
    }

    return 0;
}
