#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100;
int arrAy[MAXN];

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int A, B, n, i;
    arrAy[1] = arrAy[2] = 1;
    while ( ~scanf("%d%d%d", &A, &B, &n ) ){
        if ( A == 0 && B == 0 && n == 0 )   break;
        for ( i = 3; i <= n; i++ ){
            arrAy[i] = ( arrAy[i-1] * A + arrAy[i-2] * B ) % 7;
            if ( arrAy[i] == 1 && 1 == arrAy[i-1] ){
                n %= ( i - 2 );
                break;
            }
        }
        if ( n )    printf("%d\n", arrAy[n] );
        else printf("%d\n", arrAy[i-2] );
    }

    return 0;
}
