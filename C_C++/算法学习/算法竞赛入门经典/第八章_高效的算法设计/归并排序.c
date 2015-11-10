#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  MAXN 10001
void Merge( int * , int , int , int );
void Merge_Sort( int *, int , int );

int main( void )
{
//    freopen( "test.txt", "r", stdin );
//    freopen( "归并排序(+测试程序运行时间).txt", "w", stdout );

    int i, n;
    int arrAy[MAXN];
    time_t start = ( double ) clock();
    scanf("%d", &n );
    for ( i = 0; i < n; i++ )
        scanf("%d", &arrAy[i] );
    Merge_Sort( arrAy, 0, n );

    for ( i = 0; i < n; i++ )
        printf("%d ", arrAy[i] );
    puts("");
    printf("执行时间:%lfs\n", ( double )( clock() - start ) / CLOCKS_PER_SEC );

    return 0;
}
void Merge_Sort( int * arr, int x, int y )
{
    if ( x < y - 1 )
    {
        int mid = ( x + y ) / 2;
        Merge_Sort( arr, x, mid );
        Merge_Sort( arr, mid, y );
        Merge( arr, x, mid, y );
    }
}
void Merge( int * arr, int x, int mid, int y )
{
    int temp[MAXN];
    int k, low = x, i = x, j = mid;

    while ( low < mid && j < y )
    {
        if ( arr[low] < arr[j] )
        {
            temp[i++] = arr[low];
            low++;
        }
        else
        {
            temp[i++] = arr[j];
            j++;
        }
    }
    if ( low >= mid )
        for ( k = j; k < y; k++ )
            temp[i++] = arr[k];
    else
        for ( k = low; k < mid; k++ )
            temp[i++] = arr[k];

    for ( i = x; i < y; i++ )
        arr[i] = temp[i];
}
