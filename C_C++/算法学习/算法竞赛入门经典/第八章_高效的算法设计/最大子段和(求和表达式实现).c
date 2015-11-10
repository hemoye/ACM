#include <stdio.h>
#define  MAXN 40

int Max_Sum( int n, int * );

int main( void )
{
    int i, n;
    int arrAy[MAXN];

    scanf("%d", &n );
    for ( i = 0; i < n; i++ )
        scanf("%d", &arrAy[i] );

    int max = Max_Sum( n, arrAy );
    printf("%d\n", max );

    return 0;
}
int Max_Sum( int n, int * ptr )
{
    int i, j;
    int sum[MAXN];
    int max = ptr[0];

    sum[0] = 0;
    for ( i = 1; i <= n; i++ )
        sum[i] = sum[i-1] + ptr[i-1];

    for ( i = 1; i <= n; i++ )
        for ( j = i; j <= n; j++ )
            max = max > sum[j] - sum[i-1] ? max : sum[j] - sum[i-1];
    return max;
}
