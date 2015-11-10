#include <iostream>
#include <cstdio>
#define  MAXN_SIZE 400

struct Queue {
    int rear;
    int front;
    char arrAy[MAXN_SIZE];
} ;

void Init( Queue & );
void push( Queue & , char & );
char pop( Queue & );
bool Judge( Queue & );

int main( int agrc, char *agrv[] )
{
    Queue Q;

    Init( Q );
    for ( char i = 'a'; i <= 'z'; i++ ){
        push( Q, i );
    }
    while ( char x = pop( Q ) ){
        printf("%c ", x );
    }
    puts("");

    return 0;
}
void Init( Queue & Q )
{
    Q.rear = 1;
    Q.front = 0;
}
void push( Queue & Q, char & x )
{
    if ( Judge( Q ) ){
        Q.arrAy[Q.rear++] = x;
    }
    return ;
}
char pop( Queue & Q )
{
    if ( Q.rear == ( Q.front + 1 ) % MAXN_SIZE ){
        return 0;
    }
    else {
        Q.front = ( Q.front + 1 ) % MAXN_SIZE;
        return Q.arrAy[Q.front];
    }
}
bool Judge( Queue & Q )
{
    if ( 0 == ( Q.rear - Q.front + MAXN_SIZE ) % MAXN_SIZE ){
        return false;
    }
    return true;
}
