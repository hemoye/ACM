#include <stdio.h>
#include <stdlib.h>
#define  MAX 100

int main( void )
{
    int num, m, n, i, j;
    int a[MAX][MAX];

    scanf("%d", &num);

    while ( num-- )
    {
        scanf("%d%d", &m, &n);

        int number = 0;

        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
                if ( a[i][j] )
                    number++;
            }
        printf("%d\n", number);
    }

    return 0;
}
