#include <iostream>

using namespace std;

struct Node {
    char data;
    Node * left;
    Node * right;
} ;

Node * Pre_Creat( void );
void Ex_Change_left_right( Node * );
void Pre_Order( Node * );

int main( void )
{
    Node * Root;

    cout << "Set a Tree by Preamble: " << endl;
    Root = Pre_Creat();
    cout << "Traversal a Tree by Preamble: ";
    Pre_Order( Root );
    cout << endl;
    cout << "The recursive method exchange about subtree." << endl;
    Ex_Change_left_right( Root );
    cout << "Traversal a Tree by Preamble: ";
    Pre_Order( Root );
    cout << endl;

    return 0;
}
Node * Pre_Creat( void )
{
    char ch;
    cin >> ch;
    if ( '#' == ch ){
        return NULL;
    }
    Node * T = new Node;
    T->data = ch;
    T->left = Pre_Creat();
    T->right = Pre_Creat();
    return T;
}
void Pre_Order( Node * T )
{
    if ( NULL != T ){
        cout << T->data << " ";
        Pre_Order( T->left );
        Pre_Order( T->right );
    }
    return ;
}
void Ex_Change_left_right( Node * T )
{
    if ( NULL == T ){
        return ;
    }
    else {
        Ex_Change_left_right( T->left );
        Ex_Change_left_right( T->right );
        Node * temp = T->left;
        T->left = T->right;
        T->right = temp;
    }
}
