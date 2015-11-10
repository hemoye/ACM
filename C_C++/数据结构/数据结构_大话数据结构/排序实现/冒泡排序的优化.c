#include <stdio.h>
#include <stdlib.h>
#define  swap(a, b, t) t = a, a = b, b = t
#define  MAX 10

int main( void )
{
    int i, j, t, flage = 1;
    int arrAy[] = {9, 0, 1, 2, 3, 4, 5, 6, 7, 8};

    for ( i = 1; i < MAX && flage; i++ )
    {
        flage = 0;//冒泡法的优化算法
        for ( j = 0; j < MAX - i; j++ )
        {
            if ( arrAy[j] > arrAy[j+1] )
            {
                swap( arrAy[j], arrAy[j+1], t );
                flage = 1;
            }
        }
    }
    for ( i = 0; i < MAX; i++ )
        printf("%d ", arrAy[i]);
    puts("");

    return 0;
}
