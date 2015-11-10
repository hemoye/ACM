#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAXN 40

typedef struct
{
    int data ;
    struct Node * Next ;
} Node , * NodePtr;

void Insert( NodePtr , int , int );
void Clear( NodePtr );
void Delete( NodePtr , int );
void UpData( NodePtr , int , int );
void getelem( NodePtr , int );
void print( NodePtr );

int main( void )
{
    char str[MAXN];
    int i, t, n, val;

    NodePtr Head = ( NodePtr ) malloc ( sizeof( Node ) ) ;
    Head->Next = NULL ;

    while ( scanf("%s", str) != EOF )
    {
        if ( 0 == strcmp(str, "exit") )
            break ;

        else if ( 0 == strcmp(str , "insert") )
        {
            scanf("%d" , &t) ;
            for ( i = 0; i < t; i++ )
            {
                scanf("%d%d" , &n , &val) ;
                Insert( Head, n , val) ;
            }
        }
        else if ( 0 == strcmp(str , "clear") )
            Clear( Head ) ;
        else if ( 0 == strcmp(str , "update") )
        {
            scanf("%d%d" , &n , &val) ;
            UpData( Head, n , val) ;
        }
        else if ( 0 == strcmp(str , "getelem") )
        {
            scanf("%d" , &n);
            getelem( Head, n );
        }
        else if ( 0 == strcmp(str , "delete") )
        {
            scanf("%d" , &n);
            Delete( Head, n );
        }
        else if ( 0 == strcmp(str, "getallelem") )
            print( Head ) ;
    }
    return 0 ;
}
void Insert( NodePtr Head, int n , int val )
{
    NodePtr q = ( NodePtr ) malloc ( sizeof( Node ) );
    int count = 1 ;

    q->data = val;
    NodePtr p = Head ;
    while ( count < n )
    {
        p = p->Next ;
        count++;
    }
    q->Next = p->Next;
    p->Next = q ;
}

void Clear( NodePtr Head )
{
    NodePtr p , q ;
    p = Head->Next ;
    for( q = p ; q != NULL; q = p )
    {
        p = p->Next ;
        free( q );
    }
    Head->Next = NULL ;
    return ;
}

void Delete( NodePtr Head, int n )
{
    NodePtr q = Head ;
    NodePtr p = Head->Next ;
    int count = 1 ;

    while ( count < n )
    {
        q = p;
        p = q->Next ;
        count++;
    }
    q->Next = p->Next ;
    printf("%d\n" , p->data) ;
    return ;
}

void UpData( NodePtr Head, int n , int val)
{
    NodePtr p = Head->Next ;
    int count = 1;
    while ( count < n )
    {
        p = p->Next ;
        count++;
    }
    p->data = val;
}
void getelem( NodePtr Head, int n )
{
    NodePtr p = Head->Next ;
    int count = 1 ;

    while ( count < n )
    {
        p = p->Next ;
        count++;
    }
    printf("%d\n" , p->data) ;
}
void print( NodePtr Head )
{
    if ( NULL == Head )
        return ;
    NodePtr p = Head->Next ;
    printf("%d" , p->data) ;

    for ( p = p->Next ; p ; p = p->Next )
        printf(" %d" , p->data) ;
    puts("");
    return ;
}
