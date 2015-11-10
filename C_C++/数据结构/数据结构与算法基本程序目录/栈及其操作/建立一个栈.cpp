#include <iostream>
#include <cstdio>
#define  MAXN_SIZE 400

struct Stack {
    int top;
    char arrAy[MAXN_SIZE];
} ;

void Init( Stack & );
void push( Stack & , char & );
char pop( Stack & );
void Destroy( Stack & );

int main( void )
{
    Stack stack;
    Init( stack );
    for ( char i = 'a'; i <= 'z'; i++ ){
        push( stack, i );
    }
    while ( char x = pop( stack ) ){
        printf("%c ", x );
    }
    puts("");

    return 0;
}
void Init( Stack & S )
{
    S.top = -1;
    return ;
}
void push( Stack & S, char & x )
{
    S.arrAy[++S.top] = x;
}
char pop( Stack & S )
{
    int &n = S.top;
    if ( n < 0 ){
        return 0;
    }
    char x = S.arrAy[n--];
    return x;
}
