#include <stdio.h>
#define  MAX 10
#define ERROR -1

int arrAy[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int HalfSearch( int n );

int main( void )
{
    int n, m;

    while ( scanf("%d", &n) != EOF )
    {m = HalfSearch( n );

    if ( m != -1 )
        printf("查找成功！元素%d位于该数组的第%d个位置.\n", n, m);
    else
        printf("查找失败！该数组没有元素%d.\n", n);}

    return 0;
}
int HalfSearch( int n )
{
    int low, mid, high;

    low = 0;
    high = MAX - 1;

    while ( low <= high )
    {
        mid = ( low + high ) / 2;

        if ( n > arrAy[mid] )
            low = mid + 1;
        else if ( n < arrAy[mid] )
            high = mid - 1;
        else
            return mid + 1;
    }
    return ERROR;
}
