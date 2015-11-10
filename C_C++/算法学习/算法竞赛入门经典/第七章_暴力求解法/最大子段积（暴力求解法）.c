#include <stdio.h>
#define  MAXN 400

int MAX( int , int );
int Max_Sum( int * , int );

int main( void )
{
    int i, j, n;
    int arrAy[MAXN];

    while ( scanf("%d", &n) != EOF )
    {
        for ( i = 0; i < n; i++ )
            scanf("%d", &arrAy[i] );
        printf("����Ӷλ�Ϊ:%d\n", Max_Sum( arrAy, n ));
    }

    return 0;
}
int MAX( int a, int b )
{
    return a > b ? a : b;
}
int Max_Sum( int * p, int n )
{
    int temp = 1, sum = 0;
    int i;

    for ( i = 0; i < n; i++ )
    {
        temp = MAX( temp * p[i], 1 );
        sum = MAX( sum, temp );
    }

    return sum;
}
