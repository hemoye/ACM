#include <stdio.h>
#include <time.h>
#define  MAXN 40

static int arrAy[MAXN];

void Merge_Sort( int , int );
void Merge( int , int , int );

int main( void )
{
    int i, n;
    time_t start;

    while ( scanf("%d", &n ) != EOF )
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
        printf("Ö´ÐÐÊ±¼ä: %lfs\n", ( double )( clock() - start ) / CLOCKS_PER_SEC );
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
    return ;
}
void Merge( int x, int mid, int y )
{
    int temp[MAXN];
    int k, i = x, low = x, j = mid;

    while ( low < mid && j < y )
    {
        if ( arrAy[low] < arrAy[j] )
            temp[i++] = arrAy[low++];
        else
            temp[i++] = arrAy[j++];
    }
    if ( low >= mid )
        for ( k = j; k < y; k++ )
            temp[i++] = arrAy[k];
    else
        for ( k = low; k < mid; k++ )
            temp[i++] = arrAy[k];
    for ( i = x; i < y; i++ )
        arrAy[i] = temp[i];
    return ;
}
