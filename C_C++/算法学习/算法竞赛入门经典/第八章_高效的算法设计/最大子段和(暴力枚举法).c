#include <stdio.h>
#define  MAXN 40

void Input( int * , int * );
int  Max_Sum( int , int * );

int main( void )
{
    int i, n, max;
    int arrAy[MAXN];

    scanf("%d", &n );
    for ( i = 0; i < n; i++ )
        scanf("%d", &arrAy[i] );

    max = Max_Sum( n, arrAy );

    printf("%d\n", max );

    return 0;
}
int Max_Sum( int n, int * ptr )
{
    int i, j, k;
    int max = ptr[0];

    for ( i = 0; i < n; i++ ){
        for ( j = i; j < n; j++ ){
            int sum = 0;
            for ( k = i; k <= j; k++ )
                sum += ptr[k];
            max = max > sum ? max : sum;
        }
    }
    return max;
}
