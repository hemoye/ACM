#include <stdio.h>
#define  MAX 1000

int main( void )
{
    int n;

    while ( scanf("%d", &n) != EOF )
    {
        if ( 0 == n )
            break;

        int a[MAX] = {0};
        int i = 0, x;

        while ( n )
        {
            a[i++] = n % 2;
            n /= 2;
        }

        i = 0;

        while ( a[i] == 0 )
            i++;
        x = pow(2, i);

        printf("%d\n", x);
    }

    return 0;
}
