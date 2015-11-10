#include <stdio.h>
#include <string.h>
#define  MAXN 10

void print_subset( int , int * , int );

int total = 0;

int main( void )
{
    int i, n;
    int arrAy[MAXN], anwser[MAXN];

    scanf("%d", &n );

    print_subset( n, anwser, 0 );

    return 0;
}
void print_subset( int n, int * ptr, int cur )
{
    int i;

    for ( i = 0; i < cur; i++ )
        printf("%d", ptr[i] );
    puts("");

    int s = cur ? ptr[cur-1] : 0;

    for ( i = s; i < n; i++ )
    {
        ptr[cur] = i + 1;
        print_subset( n, ptr, cur + 1 );
    }

    return ;
}
