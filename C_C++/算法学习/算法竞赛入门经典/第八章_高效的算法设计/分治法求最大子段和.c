#include <stdio.h>
#include <stdlib.h>
#define  MAXN 40

static int arrAy[MAXN];
int Max_Sum( int , int );

int main( void )
{
    freopen( "test.txt", "r", stdin );

    int i, n;

    scanf("%d", &n );
    for ( i = 0; i < n; i++ )
        scanf("%d", &arrAy[i] );

    printf("%d\n", Max_Sum( 0, n ) );

    return 0;
}
int Max_Sum( int x, int y )
{
    if ( y - x == 1 )
        return arrAy[x] > arrAy[y] ? arrAy[x] : arrAy[y];

    int i, sum = 0, lsum = 0, rsum = 0;
    int sum1 = 0, sum2 = 0;
    int mid = ( x + y ) / 2;
    int leftsum = Max_Sum( x, mid );
    int rightsum = Max_Sum( mid, y );

    sum = leftsum > rightsum ? leftsum : rightsum;

    for (i = mid - 1; i >= 0; i-- )/**注意：这的i必须从mid-1开始逐级递减，而不能从0开始逐级递加**/
    {
        lsum += arrAy[i];
        if ( lsum > sum1 )
            sum1 = lsum;
    }
    for ( i = mid; i < y; i++ )
    {
        rsum += arrAy[i];
        if ( rsum > sum2 )
            sum2 = rsum;
    }
    return sum > ( sum1 + sum2 ) ? sum : ( sum1 + sum2 );
}
