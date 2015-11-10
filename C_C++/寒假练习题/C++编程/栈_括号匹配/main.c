#include <stdio.h>
#include <stdlib.h>
#define  MAX 40

typedef struct
{
    char data;
    struct LikeNode * Next;
} LikeNode, * LikeStack;

typedef struct
{
    struct StackNode * Top;
    int count;
} StackNode;

StackNode * ptr;

void push( char );
char pop( void );
int  Judge( void );

int main( void )
{
    ptr = ( StackNode * )malloc( sizeof( StackNode ) );
    ptr->count = 0;
    char exper[MAX];

    while ( gets( exper ) != NULL )
    {
        char *p = exper;
        int ok = 1;

        while ( *p )
        {
            if ( *p == '(' || *p == '[' || *p == '{' )
                push( *p );
            else if ( *p == ')' || *p == ']' || *p == '}' )
            {
                char temp = pop();

                if ( *p - temp != 1 && *p - temp != 2 )
                {
                    printf("NO\n");
                    ok = 0;
                    break;
                }
            }
            *p++;
        }
        if ( Judge() )
            printf("YES\n");
        else if ( ok )
            printf("NO\n");
    }

    return 0;
}
void push( char ch )
{
    LikeStack temp = ( LikeStack )malloc( sizeof(LikeNode ) );

    temp->data = ch;
    temp->Next = ptr->Top;
    ptr->Top = temp;
    ptr->count++;

    return ;
}
char pop( void )
{
    LikeStack temp;
    char x;

    if ( 0 == ptr->count )
        return 0;

    temp = ptr->Top;
    x = temp->data;
    ptr->count--;
    ptr->Top = temp->Next;
    free( temp );

    return x;
}
int Judge( void )
{
    if ( 0 == ptr->count )
        return 1;
    return 0;
}
