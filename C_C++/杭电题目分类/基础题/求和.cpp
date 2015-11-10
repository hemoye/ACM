#include <cstdio>

int main( int agrc, char *agrv[] )
{
    int n;
    while ( ~scanf("%d", &n ) ){
        int sum(0);
        for ( int i = 1; i <= n; i++ )  sum += i;
        printf("%d\n\n", sum );
    }

    return 0;
}
