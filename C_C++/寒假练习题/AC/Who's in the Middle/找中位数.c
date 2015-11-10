#include <stdio.h>
#define  MAX 30000
#define swap(a, b, t) t = a, a = b, b = t

int main( void )
{
    int i, j, n, temp;
    int arrAy[MAX];

    scanf("%d", &n);

    for ( i = 0; i < n; i++ )
        scanf("%d", &arrAy[i]);

    for ( i = 1; i < n; i++ )
        for ( j = 0; j < n - i; j++ )
            if ( arrAy[j] > arrAy[j+1] )
                swap( arrAy[j], arrAy[j+1], temp );

    printf("%d\n", arrAy[n/2]);

    return 0;
}
