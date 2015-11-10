#include <stdio.h>
#include <stdlib.h>
#define  MAXN 40

void Nextval( char * , int * );
int  Kmp_Math( char * , char * );

int main( void )
{
    int result;
    char str[MAXN], ch[MAXN];

    while ( scanf("%s%s", str, ch ) != EOF )
    {
        result = Kmp_Math( str, ch );

        if ( -1 == result )
            printf("Sorry! search failed.\n");
        else
            printf("Success! find the first char is location of the %dth.\n", result + 1 );
    }

    return 0;
}
int Kmp_Math( char * s, char * c )
{
    int Next[MAXN];
    Nextval( c, Next );

    int i = 0, j = 0;

    while ( s[i] != '\0' )
    {
        if ( -1 == j || s[i] == c[j] )
        {
            i++;
            j++;
        }
        else
            j = Next[j];

        if ( c[j] == '\0' )
            return i - j;
    }
    return -1;
}
void Nextval( char * c, int * Next )
{
    int j = 0, k = -1;
    int len = strlen( c );
    Next[0] = -1;

    while ( c[j] != '\0' )
    {
        if ( -1 == k || c[j] == c[k] )
        {
            j++;
            k++;

            if ( c[j] != c[k] )
                Next[j] = k;
            else
                Next[j] = Next[k];
        }
        else
            k = Next[k];
    }
    for ( j = 0; j < len; j++ )
        printf("%d", Next[j]);
    puts("");
    return ;
}
