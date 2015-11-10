#include <iostream>
#include <cstring>
#include <cstdio>
#define  MAXN 400

void Find_post( char * , char * , int );

int main( int argc , char *argv[] )
{
    char pre[MAXN], in[MAXN];
    int len;

    scanf("%s%s", pre, in );
    len = strlen( pre );
    Find_post( pre, in, len );
    puts("");

    return 0;
}
void Find_post( char * pre, char * in, int len )
{
    if ( len <= 0 ){
        return ;
    }
    else {
        int p = strchr( in, pre[0] ) - in;
        Find_post( pre + 1, in, p );
        Find_post( pre + 1 + p, in + p + 1, len - p - 1 );
        printf("%c ", in[p] );
    }
}
