#include <stdio.h>
#include <assert.h>

int is_prime( int x )
{
    int i;

    assert(x >= 0);

    for ( i = 2; i <= sqrt( x ); i++ )
        if ( 0 == x % i )
            return 0;
    return 1;
}

int main( void )
{
    int x;

    scanf("%d", &x);

    if ( is_prime( x ) )
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
