#include <cstdio>
#include <cstring>
#define  MAXN 104

int main( int agrc, char *agrv[] )
{
    int T, n, m;
    int arrAy[MAXN][MAXN];
    //memset( arrAy, 0, sizeof( arrAy ) );
    arrAy[1][1] = 1;
    for ( int i = 1; i <= 100; i++ ){
        for ( int j = 1; j <= 100; j++ ){
            if ( i < j ){
                arrAy[i][j] = arrAy[i][i];
            }
            else if ( i == j ){
                arrAy[i][j] = arrAy[i][j-1] + 1;
            }
            else {
                arrAy[i][j] = arrAy[i-j][j] + arrAy[i][j-1];
            }
        }
    }
    scanf("%d", &T );
    for ( int i = 0; i < T; i++ ){
        scanf("%d%d", &m, &n );
        printf("%d\n", arrAy[n][m] );
    }

    return 0;
}
