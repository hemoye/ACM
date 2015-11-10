#include <iostream>

using namespace std;

struct Node {
    char data;
    Node * left;
    Node * right;
    Node * praent;
} ;

Node * Post_Creat_Tree( void );
void Pre_Traversal( Node * );

int main( void )
{
    Node * Root = Post_Creat_Tree();
    Pre_Traversal( Root );

    return 0;
}
Node * Post_Creat_Tree( void )
{
    Node * Root = new Node;
    char ch;

    while ( cin >> ch ){
        if ( '#' == ch ){

        }
    }
}
void Pre_Traversal( Node * T )
{
    if ( NULL != T ){
        cout << T->data;
        Pre_Traversal( T->left );
        Pre_Traversal( T->right );
        return ;
    }
}
