#include <stdio.h>
#include <string.h>
#define  MAX 40

void Pre( int , char * , char * );

int main( void )
{
    char str[MAX], ch[MAX];

    while ( scanf("%s%s", str, ch ) != EOF ){
        Pre( strlen( str ), str, ch );
        puts("");
    }

    return 0;
}
void Pre( int n, char * s, char * c )
{
    if ( n <= 0 ){
        return ;
    }
    int p = strchr( s, c[n-1] ) - s;
    printf("%c", c[n-1] );
    Pre( p, s, c );
    Pre( n - 1 - p, s + 1 + p, c + p );

    return ;
}
