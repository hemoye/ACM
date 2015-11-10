#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50004;
const char sss[3][10] = { "query", "add", "sub" };

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int m, n;
    int a, b;
    int arrAy[MAXN];
    int std[MAXN];
    char str[30];

    scanf("%d%d", &m, &n );
    for ( int i = 0; i < m; i++ )   scanf("%d", arrAy + i );
    for ( int i = 0; i < n; i++ ){
        scanf("%s%d%d", str, &a, &b );
        if ( !strcmp( str, sss[0] ) ){
            int sum(0);
            for ( int i = a - 1; i < b; i++ )   sum += arrAy[i];
            printf("%d\n", sum );
        }
        else if ( !strcmp( str, sss[1] ) )  arrAy[a-1] += b;
        else arrAy[a-1] -= b;
    }

    return 0;
}
