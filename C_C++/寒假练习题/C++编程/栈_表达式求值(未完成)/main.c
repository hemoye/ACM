#include <stdio.h>
#include <stdlib.h>
#define  MAX 400

struct StackNUM
{
    int num[MAX];
    int n;
} NUM;
struct StackCHR
{
    char chr[MAX];
    int c;
} CHR;
int main()
{
    NUM.n = CHR.c = 0;
    char ch[MAX];

    while ( gets( ch ) != NULL )
    {
        int i, j, m;

        for ( i = 0; ch[i] != '\0'; i++ )
        {
            m = 0;
            if ( ch[i] >= '0' && ch[i] <= '9' )
                m = m * 10 + ( ch[i] - '0' );
            else if ( '-' == ch[i] || '+' == ch[i] || '*' == ch[i] || '/' == ch[i] )
                ;
            else if ( '(' == ch[i] || '[' == ch[i] || '{' == ch[i] )
                ;
            else if ( ')' == ch[i] || ']' == ch[i] || '}' == ch[i] )
                ;
        }
    }

    return 0;
}
