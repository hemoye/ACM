#include <stdio.h>
#include <stdlib.h>
#define  MAXN 81

int count = 1;

void Nextval( char * , int * );
int  KMP_Math( char *, char * );

int main( void )
{
    char str[MAXN], ch[MAXN];
    int pos;

    printf("Please enter two String: \n");
    scanf("%s%s", str, ch );

    pos = KMP_Math( str, ch );

    if ( -1 == pos )
        printf("Search %d, but failed.\n", count );
    else
        printf("Search %d, the first location is %d.\n", count, pos + 1 );

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

            if ( str[i] != str[k] )
                Next[i] = k;
            else
                Next[i] = Next[k];
        }
        else
            k = Next[k];
    }
    return ;
}
int KMP_Math( char * str, char * ch )
{
    int Next[MAXN];
    Nextval( ch, Next );

    int i = 0, j = 0;

    while ( str[i] != '\0' )
    {
        if ( -1 == j || str[i] == ch[j] )
        {
            i++;
            j++;
        }
        else
        {
            j = Next[j];
            count++;
        }

        if ( ch[j] == '\0' )
            return i - j;
    }
    return -1;
}
