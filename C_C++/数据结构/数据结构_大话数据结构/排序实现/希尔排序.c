#include <stdio.h>
#include <stdlib.h>
#define  swap(a, b, t) t = a, a = b, b = t
#define  MAX 10

int main( void )
{
    int i, j, V, temp, t = MAX;
    int arrAy[] = {9, 0, 1, 5, 8, 3, 7, 4, 6, 2};

    for ( i = 0; i < MAX; i++ )
        printf("%d ", arrAy[i]);
    puts("");

    do
    {
        t = t / 3 + 1;
        for ( i = t; i < MAX; i++ )
        {
            if ( arrAy[i] < arrAy[i-t] )
            {
                temp = arrAy[i];
                for ( j = i - t; j >= 0 && temp < arrAy[j]; j -= t )
                    arrAy[j+t] = arrAy[j];
                arrAy[j+t] = temp;
            }
        }
    }
    while ( t > 1 );

    for ( i = 0; i < MAX; i++ )
        printf("%d ", arrAy[i]);
    puts("");

    return 0;
}
