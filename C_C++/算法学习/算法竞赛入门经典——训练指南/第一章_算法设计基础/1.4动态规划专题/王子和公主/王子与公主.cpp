#include <cstdio>
#include <cstring>
#include <algorithm>
#define  MAXN 251 * 251
using namespace std;

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "in.in", "r", stdin );
#endif
    int T;
    int N, p, q, x;
    int arrAy[MAXN], stack[MAXN];
    int S[MAXN];

    scanf("%d", &T );
    for ( int kase = 1; kase <= T; kase++ ){
        memset( arrAy, 0, sizeof( arrAy ) );
        scanf("%d%d%d", &N, &p, &q );
        for ( int i = 0; i <= p; i++ ){
            scanf("%d", &x );
            arrAy[x] = i;
        }
        int n(0);
        for ( int i = 0; i <= q; i++ ){
            scanf("%d", &x );
            if ( arrAy[x] ){
                S[n++] = x;
            }
        }
        int top(0);
        stack[0] = -1;
        for ( int i = 0; i < n; i++ ){
            if ( S[i] > stack[top] ){
                stack[++top] = S[i];
            }
            else {
                int k = lower_bound( stack, stack + top, S[i] ) - stack;
                stack[k] = S[i];
            }
        }
        printf("Case %d: %d\n", kase, top );
    }

    return 0;
}
