#include <stdio.h>

int sum(int m, int n)
{
    if ( 1 == n )
        return 1;
    if ( m < 0 )
        return 0;
    return sum(m - n, n) + sum( m, n - 1 );
}

int main(void)
{
    int t;
    int m, n;

    scanf("%d", &t);

    while ( t-- )
    {
        scanf("%d%d", &m, &n);
        printf("%d\n", sum(m, n));
    }

    return 0;
}
