#include <stdio.h>
#include <stdlib.h>
#define  MAXN 2001

typedef struct
{
    char data;
    struct BiTree * left;
    struct BiTree * right;
} BiTree, * BiTreePtr;

BiTreePtr Creat_Tree( char * );
void In_print_Tree( BiTreePtr );
void Ord_print_Tree( BiTreePtr );
void print_Tree( BiTreePtr );

int i;

int main( void )
{
    BiTreePtr Tree;
    char str[MAXN];

    while ( gets( str ) != NULL )
    {
        i = 0;
        Tree = Creat_Tree( str );
        In_print_Tree( Tree );
        printf(" ");
        Ord_print_Tree( Tree );
        printf(" ");
        print_Tree( Tree );
        puts("");
    }

    return 0;
}
BiTreePtr Creat_Tree( char * str )
{
    if ( '#' == str[i] )
    {
        i++;
        return NULL;
    }

    BiTreePtr New_Tree = ( BiTreePtr )malloc( sizeof( BiTree ) );

    New_Tree->data = str[i];
    i++;
    New_Tree->left = Creat_Tree( str );
    New_Tree->right = Creat_Tree( str );
}
void In_print_Tree( BiTreePtr T )
{
    if ( NULL == T )
        return ;
    In_print_Tree( T->left );
    printf("%c", T->data );
    In_print_Tree( T->right );
}
void Ord_print_Tree( BiTreePtr T )
{
    if ( NULL == T )
        return ;
    Ord_print_Tree( T->left );
    Ord_print_Tree( T->right );
    printf("%c", T->data );
}
void print_Tree( BiTreePtr T )
{
    if ( NULL == T )
        return ;
    int front = 0, rear = 0;
    BiTreePtr Q[MAXN];

    Q[rear++] = T;

    while ( front < rear )
    {
        BiTreePtr temp = Q[front++];
        printf("%c", temp->data);

        if ( temp->left )
            Q[rear++] = temp->left;
        if ( temp->right )
            Q[rear++] = temp->right;
    }
}
