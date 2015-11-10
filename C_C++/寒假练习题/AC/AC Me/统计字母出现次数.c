#include <stdio.h>
#define  NAX 1000
#define  NUM 26

int main( void )
{
    char ch[NAX];
    int i;

    while ( gets(ch) != NULL )
    {
        int time[NUM] = {0};

        for ( i = 0; i < strlen(ch); i++ )
            if ( ch[i] >= 'a' && ch[i] <= 'z' )
                time[ch[i]-'a']++;

        for ( i = 0; i < NUM; i++ )
            printf("%c:%d\n", i+'a', time[i]);
    }

    return 0;
}
