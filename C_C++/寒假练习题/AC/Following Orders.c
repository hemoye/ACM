#include <stdio.h>
#include <string.h>
#define  MAXN 51

char mat[MAXN][MAXN];
int  vis[MAXN][MAXN];

void Clean( char * );

int main( void )
{
    char str[2*MAXN], ch[2*MAXN];
    int i, j;

    while ( gets( str ) != NULL )
    {
        getchar();
        Clean( str );
        gets( ch );
        Clean( ch );

        int len = strlen( str );
    }

    return 0;
}
void Clean( char * s )
{
    int i, j;
    int len = strlen( s );

    for ( i = 0; i < len; i++ )
        if ( ' ' == s[i] )
            for ( j = i; j < len; j++ )
                s[j] = s[j+1];
    return ;
}
