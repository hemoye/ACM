#include <cstdio>
#include <algorithm>
#define  MAXN 1004
using namespace std;

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test1.in", "r", stdin );
#endif
    int n, x;
    int stack[MAXN];
    stack[0] = -1;

    int top(0);
    scanf("%d", &n );
    for ( int i = 0; i < n; i++ ){
        scanf("%d", &x );
        if ( x > stack[top] ){
            stack[++top] = x;
        }
        else {
            int low = lower_bound( stack, stack + top, x ) - stack;/**按从小大到的顺序，x能排在数组stack最靠前的元素下标**/
            stack[low] = x;
        }
    }
    printf("%d\n", top );

    return 0;
}
