#include <cstdio>
#include <ctime>
#include <algorithm>
#define  MAXN 200
#define  MMMM 20

int main( int agrc, char *agrv[] )
{
    freopen( "test.out", "w", stdout );
    srand( time( NULL ) );
    for ( int i = 1; i <= MAXN; i++ ){
        printf("%c\n", rand() % 26 + 'A');
    }

    return 0;
}
