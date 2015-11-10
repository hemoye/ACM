#include <stdio.h>
#include <stdlib.h>
#define  MAXN 81

int count = 1;

void Nextval( char * , int * );

int main( void )
{
    char ch[MAXN];
    int  Next[MAXN];
    int pos;

    printf("Please enter a String: \n");
    scanf("%s", ch );

    Nextval( ch, Next );

    return 0;
}
void Nextval( char * str, int * Next )
{
    int i = 0, k = -1;
    Next[0] = -1;

    while ( str[i] != '\0' )
    {
        if ( -1 == k || str[i] == str[k] )
        {
            i++;
            k++;
            Next[i] = k;
        }
        else
            k = Next[k];
    }

    for ( i = 0; str[i]; i++ )
        printf("%d ", Next[i] + 1 );
    puts("");

    return ;
}
