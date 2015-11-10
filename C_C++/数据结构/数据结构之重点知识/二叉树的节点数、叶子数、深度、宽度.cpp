#include <iostream>
#include <cstring>
#include <cstdio>
#define  MAXN 400

struct Node {
    char data;
    Node * left;
    Node * right;
} ;

Node * Pre_Creat_Tree( void );
int  Tree_Num_Node( Node * );
int  Tree_Width( Node * , int );
int  Tree_High( Node * );
int  Tree_Leaf( Node * );
int  Max( void );

int  arrAy[MAXN];   /**全局变量，记录每一层的节点数目，用于计算树的宽度**/

int main( void )
{
    Node * Root;

    printf("Set a Tree by preamble.\n");
    Root = Pre_Creat_Tree();
    printf("The height of the tree is: %d\n", Tree_High( Root ) );
    printf("The Node-number of the tree is: %d\n", Tree_Num_Node( Root ) );
    printf("The leaf of the tree is: %d\n", Tree_Leaf( Root ) );
    memset( arrAy, 0, sizeof( arrAy ) );
    printf("The width of the tree is: %d\n", Tree_Width( Root, 1 ) );

    return 0;
}
Node * Pre_Creat_Tree( void )
{
    char ch;
    scanf("%c", &ch );

    if ( '#' == ch ){
        return NULL;
    }
    else {
        Node * T = new Node;
        T->data = ch;
        T->left = Pre_Creat_Tree();
        T->right = Pre_Creat_Tree();
        return T;
    }
}
int Tree_High( Node * T )
{
    if ( NULL == T ){
        return 0;
    }
    else {
        int left = Tree_High( T->left ) + 1;
        int right = Tree_High( T->right ) + 1;
        return left > right ? left : right;
    }
}
int Tree_Num_Node( Node * T )
{
    if ( NULL == T ){
        return 0;
    }
    else {
        return Tree_Num_Node( T->left ) + Tree_Num_Node( T->right ) + 1;
    }
}
int Tree_Leaf( Node * T )
{
    if ( NULL == T ){
        return 0;
    }
    else if ( NULL == T->left && NULL == T->right ){
        return 1;
    }
    return Tree_Leaf( T->left ) + Tree_Leaf( T->right );
}
int Tree_Width( Node * T, int layer )
{
    if ( NULL == T ){
        return 0;
    }
    else {
        if ( NULL != T->left ){
            arrAy[layer]++;
            Tree_Width( T->left, layer + 1 );
        }
        if ( NULL != T->right ){
            arrAy[layer]++;
            Tree_Width( T->right, layer + 1 );
        }
    }
    return Max();
}
int Max( void )
{
    int i;
    int t = 1;
    for ( i = 1; i < MAXN; i++ ){
        if ( t < arrAy[i] ){
            t = arrAy[i];
        }
    }
    return t;
}
