#include <stdio.h>

int main( void )
{
    unsigned s, m, n;

    while (scanf("%d%d%d", &s, &m, &n) != EOF)
    {
        if ( 0 == s && 0 == m && 0 == n)
            break;

        int sum = 0, time = 0;

        while ( sum < s - m )
        {
            time += 2;
            sum += m - n;
        }
        printf("%d\n", time + 1);
    }

    return 0;
}
