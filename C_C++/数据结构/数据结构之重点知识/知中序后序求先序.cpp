#include <iostream>
#include <cstring>
#include <cstdio>
#define  MAXN 400

void Find_pre( char * , char * , int );

int main( int argc, int *argv[] )
{
    char in[MAXN], post[MAXN];

    scanf("%s%s", in, post );
    Find_pre( in, post, strlen( in ) );
    puts("");

    return 0;
}
void Find_pre( char * in, char * post, int len )
{
    if ( len <= 0 ){
        return ;
    }
    else {
        int p = strchr( in, post[len-1] ) - in;
        printf("%c ", in[p] );
        Find_pre( in, post, p );
        Find_pre( in + p + 1, post + p, len - p - 1 );
    }
}
