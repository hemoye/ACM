#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  MAX 400

void Ord( int , char * , char * );

int main( void )
{
    char str[MAX], ch[MAX];

    while ( scanf("%s%s", str, ch ) != EOF ){
        Ord( strlen( str ), str, ch );
        puts("");
    }

    return 0;
}
void Ord( int n, char * s, char * c )
{
    if ( n <= 0 ){
        return ;
    }
    int p = strchr( c, s[0] ) - c;
    Ord( p, s + 1, c );                         /*���ҵ���ԭ�ұߵ�Ԫ�أ����Ȼ�ԭ��������*/
    Ord( n - p - 1, s + p + 1, c + p + 1 );
    printf("%c", s[0]);

    return 0;
}
