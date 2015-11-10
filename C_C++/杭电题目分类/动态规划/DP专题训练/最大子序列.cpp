#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10004;

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n;
    int data[MAXN];
    while ( ~scanf("%d", &n ) && n ){
        for ( int i = 0; i < n; i++ ){
            scanf("%d", data + i );
        }
        int x(0), y(n);
        int Max(0), sum(0);
        for ( int i = 0; i < n; i++ ){
            sum += data[i];
            if ( sum < 0 ){
                sum = 0;
            }
            if ( sum < data[i] ){
                sum = i;
            }
            if ( sum > Max ){
                Max = sum;
                y = i;
            }
        }
        printf("%d %d %d\n", Max, data[x], data[y] );
    }

    return 0;
}
