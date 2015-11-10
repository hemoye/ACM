#include <iostream>
#include <cstring>
#include <cstdio>
#define  MAXN 400

struct Node {
    char data;
    Node * left;
    Node * right;
} ;

Node * Level_creat_tree( char * , int );
void In_order( Node * );

int main( void )
{
    Node * Root;
    char arrAy[MAXN];

    memset( arrAy, '#', sizeof( arrAy ) );
    printf("Please enter a array be used to Set a Tree by level: ");
    scanf("%s", arrAy );
    Root = Level_creat_tree( arrAy, 0 );
    printf("Traversal a tree by inorder£»");
    In_order( Root );
    puts("");

    return 0;
}
Node * Level_creat_tree( char * arrAy, int n )
{
    if ( '#' == arrAy[n] ){
        return NULL;
    }
    else {
        Node * T = new Node;
        T->data = arrAy[n];
        T->left = Level_creat_tree( arrAy, 2 * n + 1 );
        T->right = Level_creat_tree( arrAy, 2 * n + 2 );
        return T;
    }
}
void In_order( Node * T )
{
    if ( NULL == T ){
        return ;
    }
    else {
        In_order( T->left );
        printf("%c ", T->data );
        In_order( T->right );
    }
}
