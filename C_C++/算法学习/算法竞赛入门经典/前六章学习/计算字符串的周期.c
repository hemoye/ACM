#include <stdio.h>
#include <string.h>

int main( void )
{
    char word[100];
    int i, j, len;

    scanf("%s", word);

    len = strlen(word);
    for ( i = 1; i <= len; i++ )
        if ( 0 == len % i )
        {
            int ok = 1;
            for ( j = i; j < len; j++ )
                if ( word[j] != word[j%i] )
                {
                    ok = 0;
                    break;
                }
            if ( ok )
            {
                printf("%d\n", i);
                break;
            }
        }

    return 0;
}
