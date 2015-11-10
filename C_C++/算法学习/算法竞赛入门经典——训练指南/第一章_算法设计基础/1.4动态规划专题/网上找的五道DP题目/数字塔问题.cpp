#include <cstdio>
#include <algorithm>
#define  MAXN 40
using namespace std;

int main( int agrc, char *agrv[] )
{
    int n;
    int arrAy[MAXN][MAXN];
    scanf("%d", &n );
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j <= i; j++ ){
            scanf("%d", &arrAy[i][j] );
        }
    }
    for ( int i = n - 1; i > 0; i-- ){
        for ( int j = 0; j < i; j++ ){
            arrAy[i-1][j] += max( arrAy[i][j], arrAy[i][j+1] );
        }
    }
    printf("%d\n", arrAy[0][0] );

    return 0;
}
