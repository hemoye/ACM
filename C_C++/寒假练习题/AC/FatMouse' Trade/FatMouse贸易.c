#include <stdio.h>
#include <stdlib.h>
#define  Swap( a, b, t ) t = a, a = b, b = t
#define  MAX 1001

struct stud
{
    int pound;
    int food;
    double sum;
} ;

int main( void )
{
    int m, n, i, j;

    while ( scanf("%d%d", &m, &n) != EOF )
    {
        struct stud temp, Node[MAX];

        if ( -1 == m && -1 == n )
            break;

        double total = 0;

        for ( i = 0; i < n; i++ )
        {
            scanf("%d%d", &Node[i].pound, &Node[i].food);

            if ( Node[i].food )
                Node[i].sum = 1.0 * Node[i].pound / Node[i].food;
            else
                Node[i].sum = 1.0 * Node[i].pound;
        }

        int change = 1;

        for ( i = 1; i < n && change; i++ )
        {
            change = 0;
            for (j = 0; j < n - i; j++ )
                if ( Node[j].sum < Node[j+1].sum )
                {
                    change = 1;
                    Swap( Node[j], Node[j+1], temp );
                }
        }

        for ( i = 0; m ; i++ )
        {
            if ( m >= Node[i].food )
            {
                m -= Node[i].food;
                total += Node[i].pound;
            }
            else
            {
                total += 1.0 * Node[i].sum * m;
                m = 0;
            }
        }
        printf("%.3lf\n", total);
    }

    return 0;
}
