#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  MAXN 1001
#define  MMMM 26

int mat[MMMM][MMMM];
int count;

void dfs( int );

int main( void )
{
    char str[MAXN];
    int i, j;
    freopen("test.txt", "r", stdin );

    while ( scanf("%s", str ) != EOF )
    {
        while ( strcmp( "0", str ) )
        {
            int len = strlen( str );
            mat[str[0]-'a'][str[len-1]-'a'] = 1;
            scanf("%s", str );
        }

        count = 0;
        dfs( 1 );
        if ( count )
            printf("Yes.\n");
        else
            printf("No.\n");
    }

    return 0;
}
void dfs( int x )
{
    if ( 'm' - 'a' == x )
    {
        count++;
        return ;
    }

    int i;
    for ( i = 0; i < MMMM; i++ )
        if ( mat[x][i] )
            dfs( i );

    return ;
}
