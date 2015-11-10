#include <stdio.h>
#include <string.h>
#define  MAXN 10

void print_subset( int , int * , int );

int arrAy[MAXN];

int main( void )
{
    int i, n;
    int anwser[MAXN];

    scanf("%d", &n );
    for ( i = 0; i < n; i++ )
        scanf("%d", &arrAy[i]);

    print_subset( n, anwser, 0 );

    return 0;
}
void print_subset( int n, int * ptr, int cur )
{
    int i;

    if ( n == cur )
    {
        for ( i = 0; i < n; i++ )
            if ( ptr[i] )
                printf("%d", arrAy[i]);
        puts("");
        return ;
    }
    ptr[cur] = 1;
    print_subset( n, ptr, cur + 1 );
    ptr[cur] = 0;
    print_subset( n, ptr, cur + 1 );
}
