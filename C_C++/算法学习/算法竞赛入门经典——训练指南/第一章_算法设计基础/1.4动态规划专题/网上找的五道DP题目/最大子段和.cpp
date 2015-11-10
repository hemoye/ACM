#include <cstdio>
#include <algorithm>
using namespace std;
/**×´Ì¬×ªÒÆ·½³Ì£º sum[i]=max(sum[i-1]+a[i],a[i])**/
int main( int agrc, char *agrv[] )
{
//    int sum(0), max(0);
    int data[10];
    int n;
    scanf("%d", &n );
    for ( int i = 0; i < n; i++ ){
        scanf("%d", data + i );
    }/*
    for ( int i = 0; i < n; i++ ){
        sum += data[i];
        if ( max < sum )    max = sum;
        if ( sum < 0 )  sum = 0;
    }
    printf("%d\n", max );
    */
    int sum[10];
    sum[0] = data[0];
    for ( int i = 1; i < n; i++ ){
        sum[i] = max( sum[i-1] + data[i], data[i] );
    }
    printf("%d\n", sum[n-1] );
    return 0;
}
