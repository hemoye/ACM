#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  MAXN 40

void Merge_Sort( int , int );
void Merge( int , int , int );

int arrAy[MAXN];

int main( void )
{
    freopen( "test.txt", "r", stdin );

    int i, n;
    time_t start;

    while ( ~scanf("%d", &n ) )
    {
        if ( 0 == n )
            break;

        start = clock();

        for ( i = 0; i < n; i++ )
            scanf("%d", &arrAy[i] );

        Merge_Sort( 0, n );
        for ( i = 0; i < n; i++ )
            printf("%d ", arrAy[i] );
        puts("");
        printf("Ö´ÐÐÊ±¼ä£º%lfs\n", ( double )( clock() - start ) / CLOCKS_PER_SEC );
    }
    return 0;
}
void Merge_Sort( int x, int y )
{
    if ( x < y - 1 )
    {
        int mid = ( x + y ) / 2;
        Merge_Sort( x, mid );
        Merge_Sort( mid, y );
        Merge( x, mid, y );
    }
}
void Merge( int low, int mid, int high )
{
    int temp[MAXN];
    int k, small = low, i = low, lage = mid;

    while ( small < mid && lage < high )
    {
        if ( arrAy[small] < arrAy[lage] )
            temp[i++] = arrAy[small++];
        else
            temp[i++] = arrAy[lage++];
    }
    if ( small >= mid )
        for ( k = lage; k < high; k++ )
            temp[i++] = arrAy[k];
    else
        for ( k = small; k < mid; k++ )
            temp[i++] = arrAy[k];
    for ( i = low; i < high; i++ )
        arrAy[i] = temp[i];
    return ;
}
