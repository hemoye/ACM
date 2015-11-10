#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  MAXN 40

void Find_Pre_print( int , char * , char * );
void change( char * );

int main( void )
{
    char str[MAXN], ch[MAXN];

    gets( str );
    gets( ch );
    Find_Pre_print( strlen( str ), str, ch );
    puts("");

    return 0;
}
void Find_Pre_print( int n, char * str, char * ch )
{
    if ( n <= 0 )
        return ;

    int p = strchr( str, ch[n-1] ) - str;
    if ( ' ' != str[p] )
    {
        printf("%c", ch[n-1] );
        Find_Pre_print( p, str, ch );
        Find_Pre_print( n - p - 1, str + 1 + p, ch + p );
    }
}
