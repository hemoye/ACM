#include <cstdio>
#include <ctime>
#include <algorithm>
#define  MAXN 999999999
#define  MMMM 20

int main( int agrc, char *agrv[] )
{
    freopen( "test.out", "w", stdout );
    srand( time( NULL ) );
    for ( int i = 1; i <= 10; i++ ){
        printf("%d %d\n", rand() + 1, rand());
    }

    return 0;
}
