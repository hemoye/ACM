#include <stdio.h>
#include <string.h>
#define  MAXN 400

void Nextval( char * , int * );
int  KMP_Match( char * , char * );

static int count = 0;

int main( void )
{
    char str1[MAXN], str2[MAXN];

    scanf("%s%s", str1, str2 );
    int time = KMP_Match( str1, str2 );

    if ( -1 == time )
        printf("匹配失败，共匹配了%d次.\n", count );
    else
        printf("匹配成功，共匹配了%d次.匹配的首位置是第%d个元素.\n", count, time );

    return 0;
}
void Nextval( char * str, int * arrAy )
{
    int j = 0, k = -1;
    int len = strlen( str );
    arrAy[0] = -1;

    while ( j < len )
    {
        if ( -1 == k || str[k] == str[j] )
        {
            j++;
            k++;
            if ( arrAy[k] != arrAy[j] )
                arrAy[j] = k;
            else
                arrAy[j] = arrAy[k];
        }
        else
            k = arrAy[k];
    }
}
int  KMP_Match( char * str, char * ch )
{
    if ( !str || !ch )
        return -1;

    int  result[MAXN];
    Nextval( ch, result );

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
            count++;
            j = result[j];
        }

        if ( ch[j] == '\0' )
            return i - j + 1;
    }

    return -1;
}
