#include <stdio.h>
#define  MAXN 40

int total = 0, n;
int Queue[MAXN];

void dfs( int );

int main( void )
{
    scanf("%d", &n);
    dfs( 0 );
    printf("%d\n", total );

    return 0;
}
void dfs( int num )
{
    int i, j;

    if ( num == n )
        total++;
    else
    {
        for ( i = 0; i < n; i++ )
        {
            int ok = 1;
            Queue[num] = i;

            for ( j = 0; j < num; j++ )
                if ( Queue[num] == Queue[j] || num - Queue[num] == j - Queue[j] || num + Queue[num] == j + Queue[j] )
                {
                    ok = 0;
                    break;
                }
            if ( ok )
                dfs( num + 1 );
        }
    }
}
