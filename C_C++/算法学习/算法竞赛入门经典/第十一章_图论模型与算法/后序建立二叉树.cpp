#include <iostream>

using namespace std;

struct Node {
    char data;
    Node * left;
    Node * right;
} ;

Node * Post_Creat_Tree( void );
void Pre_Traversal( Node * );

int main( void )
{
    Node * Root = Post_Creat_Tree();
    Pre_Traversal( Root );
    cout << endl;

    return 0;
}
Node * Post_Creat_Tree( void )
{
    char ch;
    cin >> ch;

    if ( '#' == ch ){
        return NULL;
    }
    else {
        Node * T = new Node;
        T->left = Post_Creat_Tree();
        T->right = Post_Creat_Tree();
        T->data = ch;

        return T;
    }
}
void Pre_Traversal( Node * T )
{
    if ( NULL == T ){
        return ;
    }
    else {
        //cout << T->data << " ";
        Pre_Traversal( T->left );
        //cout << T->data << " ";
        Pre_Traversal( T->right );
        cout << T->data << " ";
    }
}
