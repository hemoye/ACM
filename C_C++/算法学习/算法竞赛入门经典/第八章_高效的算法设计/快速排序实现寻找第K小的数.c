#include <stdio.h>
#include <time.h>
#define  MAXN 1000000

static int n, k;
static int arrAy[MAXN];

void Quick_Sort( int , int );
int  Find_Pos( int , int );

int main( void )
{
    int i;

    while ( scanf("%d", &n ) != EOF )
    {
        for ( i = 0; i < n; i++ )
            scanf("%d", &arrAy[i] );
        scanf("%d", &k );

        Quick_Sort( 0, n - 1 );
        printf("%d\n", arrAy[k-1] );
    }

    return 0;
}
void Quick_Sort( int low, int high )
{
    int pos;

    if ( low < high )
    {
        pos = Find_Pos( low, high );
        if ( pos < k )
            Quick_Sort( pos + 1, high );
        else
            Quick_Sort( low, pos - 1 );
    }
    return ;
}
int Find_Pos( int low, int high )
{
    int val = arrAy[low];

    while ( low < high )
    {
        while ( low < high && arrAy[high] >= val )
            high--;
        arrAy[low] = arrAy[high];
        while ( low < high && arrAy[low] <= val )
            low++;
        arrAy[high] = arrAy[low];
    }
    arrAy[low] = val;
    return low;
}
