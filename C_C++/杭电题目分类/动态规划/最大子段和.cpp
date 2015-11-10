#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int T, kase(0);
    scanf("%d", &T );
    while ( T-- ){
        int n, x;
        int cnt(0), end(0), begin(0);
        int num(0), sum(-9999);
        scanf("%d", &n );
        int z = n;
        while ( n-- ){
            scanf("%d", &x );
            num += x;
            cnt++;
            if ( sum < num ){
                sum = num;
                begin = cnt;
                end = z - n;
            }
            if ( num < 0 ){
                num = 0;
                cnt = 0;
            }
        }
        printf("Case %d:\n%d %d %d\n", ++kase, sum, begin - end + 1, end );
        if ( T )    puts("");
    }

    return 0;
}
