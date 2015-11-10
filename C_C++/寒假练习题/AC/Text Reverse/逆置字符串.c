#include <stdio.h>
#define MAX 1001
#define pop stack[top--]

int top = 0;
char stack[MAX];

void push( char ch )
{
    top++;
    stack[top] = ch;

    return ;
}

int main(void)
{
    int time, i;
    char str[MAX];

    scanf("%d", &time);
    stack[0] = getchar();

    while( time-- )
    {
        gets(str);

        for(i = 0; str[i] != '\0'; i ++)
        {
            if( str[i] != ' ' )
                push(str[i]);
            else
            {
                while( top )
                    printf("%c", pop);
                putchar(' ');
                memset( stack, '\0', sizeof( stack ) );
            }
        }

        while( top )
            printf("%c", pop);
        puts("");
    }

    return 0;
}
