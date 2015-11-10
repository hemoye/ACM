#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100004;

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n;
    int high[MAXN];
    int left[MAXN], right[MAXN];
    while ( ~scanf("%d", &n ) && n ){
        for ( int i = 0; i < n; i++ ){
            scanf("%d", high + i );
            right[i] = left[i] = i;
        }
        for ( int i = 0; i < n; i++ ){
            while ( high[i] <= high[left[i]-1] && left[i] > 0 )   left[i] = left[left[i]-1];
        }
        for ( int i = n - 1; i >= 0; i-- ){
            while ( high[i] <= high[right[i]+1] && right[i] < n - 1 )  right[i] = right[right[i]+1];
        }
        int ans(0);
        for ( int i = 0; i < n; i++ ){
            int area = high[i] * ( right[i] - left[i] + 1 );
            ans = max( ans, area );
        }
        printf("%d\n", ans );
    }

    return 0;
}
