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

void Init( void );
void push( char );
char pop( void );
void Traverse( void );
int  Judge ( void );

int main( void )
{
    char exper[MAX];

    while ( gets(exper) != NULL )
    {
        int i = 0;
        char *p = exper;

        Init();

        while ( *p )
        {
            if ( *p == '#' )
                pop();
            else if ( *p == '@' )
                while ( ' ' != pop( ) )
                {
                    if ( ptr->count == 0 )
                        break;
                }
            else
                push( *p );
            *p++;
        }
        while ( ptr->count )
            exper[i++] = pop();
        exper[i] = '\0';
        while ( i-- >= 0 )
            printf("%c", exper[i]);
        puts("");
    }

    return 0;
}
void Init( void )
{
    ptr = ( StackNode * )malloc( sizeof( StackNode ) );
    ptr->count = 0;
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
    LikeStack temp = ( LikeStack )malloc( sizeof( LikeNode ) );
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
void Traverse( void )
{
    int x = 1;
    LikeStack temp = ( LikeStack )malloc( sizeof( LikeNode ) );
    temp->Next = ptr->Top;
    char str[1000];

    if ( x == 0 )
    {
        printf("遍历失败！该栈为空栈\n");
        getch();
        return ;
    }

    while ( x++ <= ptr->count )
    {
        temp = temp->Next;
        printf("%c", temp->data);
    }

    return ;
}
int Judge( void )
{
    if ( 0 == ptr->count )
        return 1;
    return 0;
}
