#include <stdio.h>
#include <time.h>
#define  MAXN 40

void Quick_Sort( int * , int , int );
int  Find_Pos( int * , int , int );

int main( void )
{
    int i, n;
    int arrAy[MAXN];
    time_t start;

    freopen( "test.txt", "r", stdin );

    while ( scanf("%d", &n ) != EOF )
    {
        if ( 0 == n )
            break;
        start = clock();

        for ( i = 0; i < n; i++ )
            scanf("%d", &arrAy[i] );

        Quick_Sort( arrAy, 0, n - 1 );
        for ( i = 0; i < n; i++ )
            printf("%d ", arrAy[i] );
        puts("");
        printf("Ö´ÐÐÊ±¼ä:%lfs\n", ( double )( clock() - start ) / CLOCKS_PER_SEC );
    }
}
void Quick_Sort( int * ptr, int low, int high )
{
    int pos;

    if ( low < high )
    {
        pos = Find_Pos( ptr, low, high );
        Quick_Sort( ptr, low, pos - 1 );
        Quick_Sort( ptr, pos + 1, high );
    }
    return ;
}
int Find_Pos( int * ptr, int low, int high )
{
    int val = ptr[low];

    while ( low < high )
    {
        while ( low < high && ptr[high] >= val )
            high--;
        ptr[low] = ptr[high];
        while ( low < high && ptr[low] <= val )
            low++;
        ptr[high] = ptr[low];
    }
    ptr[low] = val;
    return low;
}
