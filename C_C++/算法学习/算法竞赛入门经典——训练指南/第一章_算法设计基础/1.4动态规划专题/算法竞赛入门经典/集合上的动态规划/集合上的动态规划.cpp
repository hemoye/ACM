#include <cstdio>
#include <cstring>
#include <algorithm>
#define  MAXN 1004
using namespace std;

int arrAy[MAXN], vis[MAXN];

int main( int agrc, char *agrv[] )
{
    int n;

    while ( ~scanf("%d", &n ) && n ){
        if ( n % 2 ){
            printf("n是偶数,请重新输入: \n");
            continue;
        }
        memset( vis, 0, sizeof( vis ) );
        for ( int i = 0; i < n; i++ ){
            scanf("%d", &arrAy[i] );
        }
    }

    return 0;
}
