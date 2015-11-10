#include <cstdio>
#include <cstring>
#define  MAXN 204

int main( int agrc, char *agrv[] )
{
    int n;
    long long arrAy[MAXN][MAXN];
    memset( arrAy, 0, sizeof( arrAy ) );
    arrAy[1][1] = 1;
    for ( int i = 1; i <= 200; i++ ){
        for ( int j = 1; j <= 200; j++ ){
            if ( i < j ){
                arrAy[i][j] = arrAy[i][i];
            }
            else if ( i == j ){
                arrAy[i][j] = arrAy[i][j-1] + 1;
            }
            else {
                arrAy[i][j] = arrAy[i][j-1] + arrAy[i-j][j];
            }
        }
    }
    while ( ~scanf("%d", &n ) ){
        printf("%llu\n", arrAy[n][n] );
    }

    return 0;
}
