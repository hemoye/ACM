#include <stdio.h>
#define  MAX 100

int main( void )
{
    unsigned n, i;
    unsigned a[MAX];

    while (scanf("%d", &n) != EOF)
    {
        if ( 0 == n )
            break;

        int time = 0;

        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);


        time += 5 + 6 * a[0];

        for (i = 1; i < n; i++)
        {
            if ( a[i] > a[i-1] )
                time += 5 + 6 * ( a[i] - a[i-1] );
            else
                time += 5 + 4 * ( a[i-1] - a[i] );
        }

        printf("%d\n", time);
    }

    return 0;
}
