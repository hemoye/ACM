#include <stdio.h>
#define  MAXN 10

int total;
void print_pre( int , int * , int );

int main( void )
{
    int n;
    int arrAy[MAXN];

    while ( scanf("%d", &n ) != EOF )
    {
        total = 0;

        print_pre( n, arrAy, 0 );
        printf("一共有%d种排列方式.\n", total );
    }
    return ;
}
void print_pre( int n, int * q, int cur )
{
    int i, j;

    if ( cur == n )
    {
        total++;

        for ( i = 0; i < n; i++ )
            printf("%d", q[i]);
        puts("");
    }
    else
    {
        for ( i = 1; i <= n; i++ )
        {
            int ok = 1;
            q[cur] = i;

            for ( j = 0; j < cur; j++ )
                if ( q[j] == q[cur] )
                {
                    ok = 0;
                    break;
                }

            if ( ok )
                print_pre( n, q, cur + 1 );
        }
    }
}
